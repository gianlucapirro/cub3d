/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:32:30 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/23 18:00:24 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

//TODO:Mlx setup and check malloc mlx
int	main(int argc, char *argv[])
{
	// t_config	config;
	// char		*fn;

	// get_fn(&fn, argv);
	// parse(fn, &config);
	// error_handling(argc, &config);
	// get_start_pos(&config);
	// config.mlx = mlx_init();
	// config.mlx_win = mlx_new_window(config.mlx, \
	// WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	// mlx_hook(config.mlx_win, 2, 1L << 0, key_press, &config);
	// mlx_loop_hook(config.mlx, render_next_frame, &config);
	// mlx_loop(config.mlx);
	(void)argc;
	(void)argv;
	t_matrix	*a;
	t_camera	cam;

	create_block(&a);
	e2h(a);
	init_camera(&cam, 1500);
	tranform_camera(&cam, a);
	return (0);
}
