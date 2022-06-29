/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:13:45 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/29 19:08:40 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief adds the 
 * 
 * @param config 
 * @param x 
 * @param y 
 * @return int 
 */
static int	is_valid_pos(t_config	*config, float x, float y)
{
	int	pos_left;
	int	pos_right;
	int	pos_top;
	int	pos_bottom;

	pos_left = (int)(x * config->block_size[0] - \
	config->player_size[0] / 2) / config->block_size[0];
	pos_right = (int)(x * config->block_size[0] + \
	config->player_size[0] / 2) / config->block_size[0];
	pos_top = (int)(y * config->block_size[1] - \
	config->player_size[1] / 2) / config->block_size[1];
	pos_bottom = (int)(y * config->block_size[1] + \
	config->player_size[1] / 2) / config->block_size[1];
	if ((config->map)[pos_top][pos_left] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_bottom][pos_left] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_top][pos_right] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_bottom][pos_right] != FLOOR)
		return (FALSE);
	config->pos[0] = x;
	config->pos[1] = y;
	return (TRUE);
}

int	rotate_player(t_config *config, float deg)
{
	rotate(config->direction, deg);
	return (SUCCES);
}

/*
This function is called in a hook, so it will wait until 
a key is pressed. If the key that is pressed matches one 
of the keycodes in the if statements an action will take place.
*/
int	key_press(int key, t_config	*config)
{
	float d[2];

	d[0] = config->direction[0] * PACE;
	d[1] = config->direction[1] * PACE;
	if (key == A || key == D)
		rotate(d, 90);
	if (key == W)
		is_valid_pos(config, config->pos[0] + d[0], config->pos[1] + d[1]);
	if (key == A)
		is_valid_pos(config, config->pos[0] - d[0], config->pos[1] - d[1]);
	if (key == S)
		is_valid_pos(config, config->pos[0] - d[0], config->pos[1] - d[1]);
	if (key == D)
		is_valid_pos(config, config->pos[0] + d[0], config->pos[1] + d[1]);
	if (key == ARROW_L)
		rotate_player(config, -5);
	if (key == ARROW_R)
		rotate_player(config, 5);
	return (0);
}
