/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:26:06 by tfiguero          #+#    #+#             */
/*   Updated: 2023/12/29 18:27:26 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	ft_handler(int signal)
{
	static int	bit = '\0';
	static int	j = 0;

	if (signal == SIGUSR2)
		bit |= (0x01 << j);
	j++;
	if (j == 8)
	{
		j = 0;
		bit = 0;
	}
}