/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:43:25 by tfiguero          #+#    #+#             */
/*   Updated: 2023/09/15 07:08:59 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

void	ft_putchar(char const c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putchar(((int)n % 10) + 48);
	}
	if (n < 10)
		ft_putchar((char)(n + 48));
}

void	ft_handler(int signal)
{
	static int	bit = '\0';
	static int	j = 0;

	if (signal == SIGUSR2)
		bit |= (0x01 << j);
	j++;
	if (j == 8)
	{
		ft_putchar(bit);
		j = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	loop;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	loop = 1;
	while (loop)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		sleep(1);
	}
	return (0);
}
