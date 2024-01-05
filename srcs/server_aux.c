/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:26:06 by tfiguero          #+#    #+#             */
/*   Updated: 2024/01/05 19:33:08 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	ft_error(int code)
{
	if(code = 1)
		write(2, "Malloc error", 12);
	exit(0);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = (void *) malloc(count * size);
	if (!ret)
		return(NULL);
	ft_memset (ret, 0, count * size);		
	return (ret);
}
void	*ft_memset(void *x, int y, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(x + i) = (unsigned char) y;
		i++;
	}
	return (x);
}