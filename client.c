/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:31:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/06 16:48:07 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "ft_printf/ft_printf.h"

// recieve PID as av[1] (the system take it as String)
// use kill to send signal to that PID
// trans function is used to convert String into binary and send signal

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

void	trans(pid_t pid, char c)
{
	int	bitshift;

	bitshift = 0;
	while (bitshift < 8)
	{
		if (c & (0x80 >> bitshift))
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		usleep(200);
		bitshift++;
	}
}

int	main(int ac, char **av)
{
	char	*str;
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("Invalid argument");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	str = av[2];
	if (pid > 0)
		while (*str)
			trans(pid, *str++);
	return (0);
}
