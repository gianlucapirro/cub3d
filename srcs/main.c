/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:32:30 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/25 14:07:56 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include <stdio.h>

int	setup_config(t_config *config)
{
	config->player_size[0] = 10;
	config->player_size[1] = 10;
	config->block_size[0] = 30;
	config->block_size[1] = 30;
	return (SUCCES);
}

//TODO:Mlx setup and check malloc mlx
int	main(int argc, char *argv[])
{
	t_config	config;
	char		*fn;

	get_fn(&fn, argv);
	setup_config(&config);
	parse(fn, &config);
	error_handling(argc, &config);
	get_start_pos(&config);
	config.mlx = mlx_init();
	config.mlx_win = mlx_new_window(config.mlx, \
	WINDOW_WIDTH, WINDOW_HEIGHT, "CUB3D");
	mlx_hook(config.mlx_win, 2, 1L << 0, key_press, &config);
	mlx_loop_hook(config.mlx, render_next_frame, &config);
	mlx_loop(config.mlx);
	return (0);
}
