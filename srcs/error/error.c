/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/19 16:41:29 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/10/28 17:02:58 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Checks if there is one start position in map.
 * 
 * 
 * @param config 
 * @return If more than one start pos return FAILED else return SUCCES
 */
static int	check_start_pos(t_config *config)
{
	int	x;
	int	y;
	int	startpos;

	startpos = 0;
	y = -1;
	while (++y < config->dimensions[1])
	{
		x = -1;
		while (++x < config->dimensions[0])
			if (is_start_pos(config->map[y][x]))
				startpos++;
	}
	if (startpos != 1)
		return (FAILED);
	return (SUCCES);
}

/**
 * @brief Loops over every item in map and if there is a 
 * invalid object return FAILED else return SUCCES
 * 
 * @param config 
 * @return FAILED or SUCCES 
 */
static int	is_invalid_obj_in_map(t_config *config)
{
	int	x;
	int	y;

	y = -1;
	while (++y < config->dimensions[1])
	{
		x = -1;
		while (++x < config->dimensions[0])
			if (config->map[y][x] == OTHER)
				return (FAILED);
	}
	return (SUCCES);
}

static int	is_surrounded_walls_h(t_config *config)
{
	int	x;
	int	y;
	int	prev;

	y = -1;
	while (++y < config->dimensions[1])
	{
		x = -1;
		prev = EMPTY;
		while (++x < config->dimensions[0])
		{
			if (config->map[y][x] == FLOOR && prev == EMPTY)
				return (FAILED);
			if (config->map[y][x] == EMPTY && prev == FLOOR)
				return (FAILED);
			prev = config->map[y][x];
		}
		if (prev == FLOOR)
			return (FAILED);
	}
	return (SUCCES);
}

static int	is_surrounded_walls_v(t_config *config)
{
	int	y;
	int	x;
	int	prev;

	x = -1;
	while (++x < config->dimensions[0])
	{
		y = -1;
		prev = EMPTY;
		while (++y < config->dimensions[1])
		{
			if (config->map[y][x] == FLOOR && prev == EMPTY)
				return (FAILED);
			if (config->map[y][x] == EMPTY && prev == FLOOR)
				return (FAILED);
			prev = config->map[y][x];
		}
		if (prev == FLOOR)
			return (FAILED);
	}
	return (SUCCES);
}

void	error_handling(int argc, t_config *config)
{
	if (argc != 2)
		exit_error("Error\nPlease give one map as an argument", ARGUMENT_ERROR);
	if (check_start_pos(config) == FAILED)
		exit_error("Error\nMap must have one start position", INVALID_MAP);
	if (is_invalid_obj_in_map(config) == FAILED)
		exit_error("Error\nMap contains invalid object(s)", INVALID_MAP);
	if (is_surrounded_walls_h(config) == FAILED)
		exit_error("Error\nMap not surrounder by walls", INVALID_MAP);
	if (is_surrounded_walls_v(config) == FAILED)
		exit_error("Error\nMap not surrounder by walls", INVALID_MAP);
}
