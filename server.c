/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:32:01 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/06 01:06:17 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

//start first and print PID
//sys/types.h is for the data type called 'pid_t'.
//pid_t represent a variable that can hold process ID
//pid_t can be printed with %d
//need to test with many test case before evaluation, test with the command
//line to random/generate String to be the argument (like 1000 word or smth)
//send String as bit then convert byte in server to be character

void	handle_sigusr1(int signum)
{
	(void)signum;
	ft_printf("1");
}

void	handle_sigusr2(int signum)
{
	(void)signum;
	ft_printf("0");
}

int	main(void)
{
	pid_t				pid;
	// struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	signal(SIGUSR1, handle_sigusr1);
	signal(SIGUSR2, handle_sigusr2);
	// sa.sa_handler = &handle_sigusr1;
	// sigemptyset(&sa.sa_mask);
	// sa.sa_flags = SA.SIGINFO;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
