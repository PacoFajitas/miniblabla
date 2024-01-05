/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfiguero <tfiguero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 18:27:29 by tfiguero          #+#    #+#             */
/*   Updated: 2024/01/05 19:21:13 by tfiguero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define	MINITALK_H
# include	<unistd.h>
# include	<signal.h>
# include	<stdlib.h>
# include	<sys/types.h>
# include	<stdio.h>

 static int	g_chars = 0;
 static char *g_str;

 void	ft_error(int code);
#endif