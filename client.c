/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:38:54 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/04 02:15:47 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_sig;

static void	send_str(char *str, pid_t pid, int len)
{
	int	i;
	int	shift;

	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift <= 7)
		{
			g_sig = 0;
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50000);
			shift++;
			while (g_sig == 0)
				pause();
		}
		i++;
	}
}

void	handler_client(int sig, siginfo_t *info, void *context)
{
	(void) info;
	(void) context;
	(void) sig;
	g_sig = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = &handler_client;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("From client: exec, pid, string.\n");
		exit (EXIT_FAILURE);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(argv[2], pid, ft_strlen(argv[2]));
	}	
	return (0);
}
