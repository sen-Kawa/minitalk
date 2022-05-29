/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaheinz <kaheinz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:01:07 by kaheinz           #+#    #+#             */
/*   Updated: 2022/05/29 16:22:09 by kaheinz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
//	struct sigaction sa;	//i need a struct for sigaction
	pid_t	pid;	//pid_t data type specific for process id
	
	pid = getpid();
	ft_printf("Process ID of server is: %d\n", pid);	
	ft_printf("test");
//	sa.
//	sigaction(SIGUSR1);

	return (0);
}
