/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaengha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:31:49 by psaengha          #+#    #+#             */
/*   Updated: 2023/07/05 18:32:05 by psaengha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

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

void	handle_sigusr1(void)
{
	printf("Client\n");
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;

	if (ac < 3)
		exit(0);
	pid = ft_atoi(av[1]);
	printf("pid: %d", pid);
	sa.sa_handler = &handle_sigusr1;
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}
