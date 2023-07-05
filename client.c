/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:31:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/06 01:08:09 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf/ft_printf.h"

// recieve PID as av[1] (the system take it as String)
// use kill to send signal to that PID

static int	checkneg(const char *str)
{
	int	n;
	int	i;
	int	count;

	n = 1;
	i = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
		count++;
	}
	if (count > 1)
		return (0);
	return (n);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	n;
	int	i;
	int	count;

	i = 0;
	n = checkneg(str);
	result = 0;
	count = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * n);
}

// void	handle_sigusr1(void)
// {
// 	printf("Client\n");
// }

//turn ascii to binary
void	trans(pid_t pid, char c)
{
	(void)pid;
	int bitshift = 0;
	while (bitshift < 8)
	{
		if (c & (0x80 >> bitshift))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(3); //if dont sleep the signal will be send too simultaneously and collapse with each other
		bitshift++;
	}
}

int	main(int ac, char **av)
{
	// struct sigaction	sa;
	char				*str;
	pid_t				pid;

	// if (ac < 3)
	// 	exit(0);
	(void)ac;
	pid = ft_atoi(av[1]);
	str = av[2];
	// printf("pid: %d\n", pid);
	// sa.sa_handler = &handle_sigusr1;
	// sigaction(SIGUSR1, &sa, NULL);
	// sigaction(SIGUSR2, &sa, NULL);
	if (pid > 0)
		while (*str)
			trans(pid, *str++);
	return (0);
}
