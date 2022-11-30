/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minimap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 12:33:15 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/11/30 14:34:49 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static int	draw_minimap_player(t_config *config, mlx_image_t *img)
{
	int	pos[2];

	pos[0] = (int)(config->pos[0] * (int)config->block_size[0] - \
	(int)(config->player_size[0] / 2));
	pos[1] = (int)(config->pos[1] * (int)config->block_size[1] - \
	(int)(config->player_size[1] / 2));
	pos[1] = img->height - pos[1];
	draw_rectangle(pos, (int *)config->player_size, img, PINK);
	return (SUCCES);
}

static int	draw_direction(t_config *config, mlx_image_t *img)
{
	t_point	p1;
	t_point	p2;

	p1.x = config->pos[0] * config->block_size[0];
	p1.y = config->pos[1] * config->block_size[1];
	p2.x = (config->pos[0] + config->direction[0]) * config->block_size[0];
	p2.y = (config->pos[1] + config->direction[1]) * config->block_size[1];
	p1.y = img->height - p1.y;
	p2.y = img->height - p2.y;
	draw_line(img, &p1, &p2, WHITE);
	return (SUCCES);
}

int	draw_minimap_line(t_config *config, \
mlx_image_t *img, float start[2], float end[2])
{
	t_point	p1;
	t_point	p2;

	p1.x = start[0] * config->block_size[0];
	p1.y = start[1] * config->block_size[1];
	p2.x = end[0] * config->block_size[0];
	p2.y = end[1] * config->block_size[1];
	draw_line(img, &p1, &p2, WHITE);
	return (SUCCES);
}

int	draw_wall(t_config *c, mlx_image_t *img_d, int wall[3], int color)
{
	t_point	s;
	t_point	e;

	set_data_wall_ns(&s, &e, wall);
	set_data_wall_ew(&s, &e, wall);
	s.x *= c->block_size[0];
	s.y *= c->block_size[1];
	e.x *= c->block_size[0];
	e.y *= c->block_size[1];
	draw_line(img_d, &s, &e, color);
	return (SUCCES);
}

int	draw_minimap(t_config *config, mlx_image_t *img)
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
			pos[1] = img->height - (y * (int)(config->block_size[1]));
			draw_rectangle(pos, config->block_size, \
			img, colors[config->map[y][x]]);
		}
	}
	draw_minimap_player(config, img);
	draw_direction(config, img);
	return (SUCCES);
}
