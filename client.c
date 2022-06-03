/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 21:38:54 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/04 00:54:21 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	global_sig;

static void	send_str(char *str, pid_t pid)
{
	int	i;
	int	len;
	int	shift;

	shift = 0;
	len = ft_strlen(str);
	i = 0;
	while (i <= len)
	{
		shift = 0;
		while (shift <= 7)
		{
			global_sig = 0;
			if ((str[i] >> shift) & 1)
			{
				kill(pid, SIGUSR1);
				usleep(50000);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(50000);
			}
			shift++;
			while (global_sig == 0)
				pause();
		}
		i++;
	}
}

void	handler_client(int sig, siginfo_t *info, void *context)
{
//	(void) sig;
	(void) info;
	(void) context;

	global_sig = 1;
	if (sig == SIGUSR1)
	{
		ft_printf("Message succesfully sent\n");
//		exit(EXIT_SUCCESS);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	struct sigaction sa;

	sa.sa_sigaction = &handler_client;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		ft_printf("From client: minimun amount of arguments is 3\n");
		exit (EXIT_FAILURE);
	}
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(argv[2], pid);
	}	
//	kill(pid, SIGUSR2);
	return (0);
}
