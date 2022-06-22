/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:13:45 by gpirro            #+#    #+#             */
/*   Updated: 2022/06/20 18:55:20 by gianlucapir      ###   ########.fr       */
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
	pos_top = (int)(y * config->block_size[1] + \
	config->player_size[1] / 2) / config->block_size[1];
	pos_bottom = (int)(y * config->block_size[1] - \
	config->player_size[1] / 2) / config->block_size[1];
	if ((config->map)[pos_top][pos_left] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_bottom][pos_left] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_top][pos_right] != FLOOR)
		return (FALSE);
	if ((config->map)[pos_bottom][pos_right] != FLOOR)
		return (FALSE);
	return (TRUE);
}

/*
This function is called in a hook, so it will wait until 
a key is pressed. If the key that is pressed matches one 
of the keycodes in the if statements an action will take place.
*/
int	key_press(int key, t_config	*config)
{
	if (key == W && is_valid_pos(config, config->pos[0], config->pos[1] - 0.05))
		config->pos[1] -= 0.05;
	if (key == A && is_valid_pos(config, config->pos[0] - 0.05, config->pos[1]))
		config->pos[0] -= 0.05;
	if (key == S && is_valid_pos(config, config->pos[0], config->pos[1] + 0.05))
		config->pos[1] += 0.05;
	if (key == D && is_valid_pos(config, config->pos[0] + 0.05, config->pos[1]))
		config->pos[0] += 0.05;
	return (0);
}
