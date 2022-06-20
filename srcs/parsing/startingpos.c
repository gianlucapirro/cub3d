/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startingpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:22 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/20 14:35:10 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	get_start_pos(t_config *config)
{
	int	x;
	int	y;
	int	p;

	x = -1;
	while (++x < config->dimensions[0])
	{
		y = -1;
		while (++y < config->dimensions[1])
		{
			p = config->map[y][x];
			if (p == START_E || p == START_N || p == START_W || p == START_S)
			{
				config->pos[0] = x + 0.5;
				config->pos[1] = y + 0.5;
				config->map[y][x] = FLOOR;
				return (SUCCES);
			}
		}
	}

	return (FAILED);
}
