/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 09:32:30 by hthomas       #+#    #+#                 */
/*   Updated: 2022/11/30 13:32:44 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

int	setup_config(t_config *config, int argc, char *argv[])
{
	char		*fn;

	config->player_size[0] = 3;
	config->player_size[1] = 3;
	config->block_size[0] = 10;
	config->block_size[1] = 10;
	config->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", true);
	if (!config->mlx)
		exit_error("MLX init failed", MALLOC_ERROR);
	get_fn(&fn, argv);
	parse(fn, config);
	error_handling(argc, config);
	get_start_pos(config);
	return (SUCCES);
}

int	main(int argc, char *argv[])
{
	t_config	config;

	setup_config(&config, argc, argv);
	config.i = 0;
	config.img = mlx_new_image(config.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_image_to_window(config.mlx, config.img, 0, 0);
	mlx_key_hook(config.mlx, key_press, (void *)&config);
	mlx_loop_hook(config.mlx, &render_next_frame, &config);
	mlx_loop(config.mlx);
	exit (SUCCES);
	return (0);
}
