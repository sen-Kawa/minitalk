/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:01:07 by kaheinz           #+#    #+#             */
/*   Updated: 2022/05/29 18:06:50 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_server()
{

}

int	main(void)
{
	struct sigaction sa;	//i need a struct for sigaction
//	pid_t	pid;	//pid_t data type specific for process id
	
//	pid = getpid();
	ft_printf("Process ID of server is: %d\n", getpid());	
	sa.sa_flags = SIGINFO //SIGINFO takes 3 args instead of 2, sa_sigaction has to be set instead of sa_handler
	sa.sa_sigaction = handler_server;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause(); //define posix source? 
	return (0);
}
