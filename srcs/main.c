/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:32:30 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/20 14:29:47 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

//TODO:Mlx setup and check malloc mlx
int	main(int argc, char *argv[])
{
	t_config	config;
	char		*fn;

	get_fn(&fn, argv);
	parse(fn, &config);

	error_handling(argc, &config);
	get_start_pos(&config);

	config.mlx = mlx_init();
	config.mlx_win = mlx_new_window(config.mlx, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	printf("mini: %d %d\n",  config.block_size[0], config.block_size[1]);

	mlx_hook(config.mlx_win, 2, 1L << 0, key_press, &config);
	mlx_loop_hook(config.mlx, render_next_frame, &config);
	mlx_loop(config.mlx);
	return (0);
}
