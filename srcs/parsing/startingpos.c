/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startingpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:22:22 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/23 18:51:13 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	set_direction(t_config *config, int p)
{
	if (p == START_N)
	{
		config->direction[0] = 0;
		config->direction[1] = 1;
	}
	if (p == START_S)
	{
		config->direction[0] = 0;
		config->direction[1] = -1;
	}
	if (p == START_E)
	{
		config->direction[0] = 1;
		config->direction[1] = 0;
	}
	if (p == START_W)
	{
		config->direction[0] = -1;
		config->direction[1] = 0;
	}
	return (SUCCES);
}

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
				set_direction(config, p);
				return (SUCCES);
			}
		}
	}
	return (FAILED);
}
