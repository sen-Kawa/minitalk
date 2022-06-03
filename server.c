/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:01:07 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/04 01:54:09 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_server(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits_received;

	(void) context;
	if (sig == SIGUSR1)
		c += 1 << bits_received;
	if (sig == SIGUSR2)
		c += 0 << bits_received;
	bits_received++;
	if (bits_received == 8)
	{
		if (c == '\0')
			ft_printf("\n");
		ft_printf("%c", c);
		c = 0;
		bits_received = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Process ID of server is: %d\n", getpid());
	sa.sa_sigaction = &handler_server;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
