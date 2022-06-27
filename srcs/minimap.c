/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:33:15 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/27 13:14:37 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	draw_minimap_player(t_config *config, t_data *img_data)
{
	int	pos[2];

	pos[0] = (int)(config->pos[0] * (int)config->block_size[0] - \
	(int)(config->player_size[0] / 2));
	pos[1] = (int)(config->pos[1] * (int)config->block_size[1] - \
	(int)(config->player_size[1] / 2));
	draw_rectangle(pos, (int *)config->player_size, img_data, PINK);
	return (SUCCES);
}

static int	draw_direction(t_config *config, t_data *img_data)
{
	t_point	p1;
	t_point	p2;

	p1.x = config->pos[0] * config->block_size[0];
	p1.y = config->pos[1] * config->block_size[1];
	p2.x = (config->pos[0] + config->direction[0]) * config->block_size[0];
	p2.y = (config->pos[1] + config->direction[1]) * config->block_size[1];
	draw_line(img_data, &p1, &p2);
	return (SUCCES);
}

int	draw_wall(t_config *c, t_data *img_d, int wall[3])
{
	t_point	s;
	t_point	e;

	if (wall[2] == NORTH)
	{
		s.x = wall[0];
		s.y = wall[1] + 1;
		e.x = wall[0] + 1;
		e.y = wall[1] + 1;
	}
	if (wall[2] == EAST)
	{
		s.x = wall[0] + 1;
		s.y = wall[1];
		e.x = wall[0] + 1;
		e.y = wall[1] + 1;
	}
	if (wall[2] == SOUTH)
	{
		s.x = wall[0];
		s.y = wall[1];
		e.x = wall[0] + 1;
		e.y = wall[1];
	}
	if (wall[2] == WEST)
	{
		s.x = wall[0];
		s.y = wall[1];
		e.x = wall[0];
		e.y = wall[1] + 1;
	}
	s.x *= c->block_size[0];
	s.y *= c->block_size[1];
	e.x *= c->block_size[0];
	e.y *= c->block_size[1];
	draw_line(img_d, &s, &e);
	return (SUCCES);
}

int	draw_minimap(t_config *config, t_data *img_data)
{
	int			x;
	int			y;
	int			colors[20];
	int			pos[2];

	colors[FLOOR] = BLACK;
	colors[WALL] = WHITE;
	colors[EMPTY] = GREY;
	x = -1;
	while (++x < config->dimensions[0])
	{
		y = -1;
		while (++y < config->dimensions[1])
		{
			pos[0] = x * (int)(config->block_size[0]);
			pos[1] = y * (int)(config->block_size[1]);
			draw_rectangle(pos, config->block_size, \
			img_data, colors[config->map[y][x]]);
		}
	}
	draw_minimap_player(config, img_data);
	draw_direction(config, img_data);
	return (SUCCES);
}

int	draw_minimap_cross(t_config *conf, t_data *img_data, float pos[2])
{
	int	mpos[2];

	mpos[0] = (int)(pos[0] * conf->block_size[0]);
	mpos[1] = (int)(pos[1] * conf->block_size[1]);
	draw_cross(img_data, mpos, 5);
	return (SUCCES);
}