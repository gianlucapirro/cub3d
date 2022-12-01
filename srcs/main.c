/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/04 09:32:30 by hthomas       #+#    #+#                 */
/*   Updated: 2022/11/30 17:24:02 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

int	setup_config(t_config *config, int argc, char *argv[])
{
	char	*fn;
	int		map_size;		

	config->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D", false);
	if (!config->mlx)
		exit_error("MLX init failed", MALLOC_ERROR);
	get_fn(&fn, argv);
	parse(fn, config);
	error_handling(argc, config);
	get_start_pos(config);
	config->player_size[0] = 3;
	config->player_size[1] = 3;
	config->draw_minimap = 1;
	map_size = config->dimensions[1];
	if (config->dimensions[0] > config->dimensions[1])
		map_size = config->dimensions[0];
	map_size = (int)(300 / map_size);
	if (map_size < 5)
	{
		config->draw_minimap = 0;
		map_size = 5;
	}
	config->block_size[0] = map_size;
	config->block_size[1] = map_size;
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
