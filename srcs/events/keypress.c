/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keypress.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/26 16:13:45 by gpirro        #+#    #+#                 */
/*   Updated: 2022/11/30 16:45:25 by gpirro        ########   odam.nl         */
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
int	is_valid_pos(t_config	*config, float x, float y)
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

static void	close_win(t_config *config)
{
	mlx_delete_image(config->mlx, config->img);
	exit(SUCCES);
}

/*
This function is called in a hook, so it will wait until 
a key is pressed. If the key that is pressed matches one 
of the keycodes in the if statements an action will take place.
*/
void	key_press(mlx_key_data_t rkey, void	*data)
{
	t_config	*config;
	int			key;

	key = rkey.os_key;
	config = (t_config *)data;
	if (key == ESC)
		close_win(config);
}
