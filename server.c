/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:32:01 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/05 18:27:33 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

//start first and print PID
//sys/types.h is for the data type called 'pid_t'.
//pid_t represent a variable that can hold process ID
//pid_t can be printed with %d

void	handle_sigusr1(void)
{
	printf("Server\n");
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("SERVER: %d\n", pid);
	sa.sa_handler = &handle_sigusr1;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA.SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
