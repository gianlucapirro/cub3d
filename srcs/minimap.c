/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:33:15 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/20 14:22:52 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


static int draw_minimap_player(t_config *config, t_data *img_data)
{
	int	pos[2];

	pos[0] = (int)(config->pos[0] * (int)config->block_size[0] - (int)(config->player_size[0] / 2));
	pos[1] = (int)(config->pos[1] * (int)config->block_size[1] - (int)(config->player_size[1] / 2));
	draw_rectangle(pos, (int *)config->player_size, img_data, PINK);
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
	return (SUCCES);
}