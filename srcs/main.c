/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:32:30 by hthomas           #+#    #+#             */
/*   Updated: 2022/07/01 16:56:30 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

/******************************************************************************/
/* Function: setup_config                                                     */
/*                                                                            */
/* Description:                                                               */
/*      This funciton set-ups the config struct with all necesarry information*/
/*      to start the game                                                     */
/*                                                                            */
/* t_config *config:                                                          */
/*      Configuration struct with all information to start the game           */
/*                                                                            */
/* int argc:                                                                  */
/*      Amount of arguments of program                                        */
/*                                                                            */
/* char *argv[]:                                                              */
/*      arguments of executable                                               */
/*                                                                            */
/* Returns (int):                                                             */
/*      SUCCES                                                                */
/*                                                                            */
/******************************************************************************/
int	setup_config(t_config *config, int argc, char *argv[])
{
	char		*fn;

	config->player_size[0] = 3;
	config->player_size[1] = 3;
	config->block_size[0] = 10;
	config->block_size[1] = 10;
	config->mlx = mlx_init();
	if (!config->mlx)
		exit_error("MLX init failed", MALLOC_ERROR);
	config->mlx_win = mlx_new_window(config->mlx, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	if (!config->mlx_win)
		exit_error("MLX WINDOW failed", MALLOC_ERROR);
	get_fn(&fn, argv);
	parse(fn, config);
	error_handling(argc, config);
	get_start_pos(config);
	return (SUCCES);
}

//TODO: make inter struct instead of float inter[2] in raycaster.c
int	main(int argc, char *argv[])
{
	t_config	config;

	setup_config(&config, argc, argv);
	mlx_hook(config.mlx_win, 2, 1L << 0, key_press, &config);
	mlx_loop_hook(config.mlx, render_next_frame, &config);
	mlx_loop(config.mlx);
	return (0);
}
