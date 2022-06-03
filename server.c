/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:01:07 by kaheinz           #+#    #+#             */
/*   Updated: 2022/06/04 00:51:37 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_server(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	bits_received;
//	static pid_t	client_pid = 0;

	(void) context;
	if (sig == SIGUSR1)
		c += 1 << bits_received;
	if (sig == SIGUSR2)
		c += 0 << bits_received;
	bits_received++;
	if (bits_received == 8)
	{
	//	ft_printf("%c", c);
		if (c == '\0')
			ft_printf("\n");
		ft_printf("%c", c);
//		kill(info->si_pid, SIGUSR1);
		c = 0;
		bits_received = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction sa;	//i need a struct for sigaction
//	pid_t	pid;	//pid_t data type specific for process id
	
//	pid = getpid(); returns PID of the calling process
	ft_printf("Process ID of server is: %d\n", getpid());	
	sa.sa_sigaction = &handler_server; //uses sigaction instead of handler due to siginfo
	sa.sa_flags = SA_SIGINFO; //SIGINFO takes 3 args instead of 2, sa_sigaction has to be set instead of sa_handler
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause(); //define posix source? 
	return (0);
}
