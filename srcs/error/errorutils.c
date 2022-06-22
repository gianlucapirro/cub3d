/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:53:29 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/20 18:52:36 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	exit_error(char *msg, int exitcode)
{
	perror(msg);
	exit(exitcode);
}

/**
 * @brief checks if char c is equal to a macro of a
 * player starting direction. START_N, START_W, START_S
 * START_E 
 * 
 * @param c 
 * @return int 
 */
int	is_start_pos(char c)
{
	if (c == START_E || c == START_N || c == START_S || c == START_W)
		return (1);
	else
		return (0);
}
