/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:31:05 by tfiguero          #+#    #+#             */
/*   Updated: 2024/01/05 18:55:48 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	ft_count_chars(char *str)
{
	int	i;
	i = 0;
	while (str[i])
		i++;
	g_chars = i;
}

int	ft_atoi(const char	*str)
{
	int	ret;
	int	sign;

	sign = 1;
	ret = 0;
	while (*str == 9 || *str == 10 || *str == 11
		|| *str == 12 || *str == 13 || *str == 32)
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -sign;
		}
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = (ret * 10) + *str - 48;
		str ++;
	}
	return (ret * sign);
}

void	ft_send(int ch, int pid, int j)
{
	while (j < 8)
	{
		if ((ch & (0x01 << j)) != 0)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "Signal error\n", 13);
				exit (0);
			}
			usleep(150);
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "Signal error\n", 13);
				exit (0);
			}
			usleep(150);
		}
		usleep(200);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		ft_count_chars(argv[3]);
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send(argv[2][i], pid, 0);
			i++;
		}
		ft_send('\n', pid, 0);
	}
	else
	{
		write(1, "Error: wrong arguments.\n", 24);
		write(1, "Try: ./client <Server PID> <\"MESSAGE\">\n", 39);
		return (1);
	}
	return (0);
}
