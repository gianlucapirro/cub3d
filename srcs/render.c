/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:35:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/12/01 10:21:32 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

unsigned int	get_pixel(mlx_texture_t *texture, float x, float y)
{
	u_int8_t	*dst;
	int			px;
	int			py;
	u_int32_t	color;

	px = (int)(texture->width * x);
	py = (int)(texture->height * y);
	dst = texture->pixels + (py * texture->width + px) * 4;
	((u_int8_t *)&color)[0] = dst[3];
	((u_int8_t *)&color)[1] = dst[2];
	((u_int8_t *)&color)[2] = dst[1];
	((u_int8_t *)&color)[3] = dst[0];
	return (color);
}

static int	put_img_col_start(mlx_image_t *img, int x, \
int start, t_config *config)
{
	int	i;

	i = -1;
	while (++i < start)
		put_pixel(img, x, i, config->ceilingcolor);
	return (0);
}

static int	put_img_col_end(mlx_image_t *img, int x, int i, t_config *config)
{
	while (++i < WINDOW_HEIGHT)
		put_pixel(img, x, i, config->floorcolor);
	return (0);
}

void	put_img_column(t_config *config, mlx_image_t *img, t_ray *ray, int x)
{
	int				i;
	float			y;
	int				end;
	int				start;

	start = (WINDOW_HEIGHT - (int)(WINDOW_HEIGHT / ray->distance)) / 2;
	end = WINDOW_HEIGHT - start;
	put_img_col_start(img, x, start, config);
	i = start - 1;
	if (i < 0)
		i = -1;
	while (++i < end && i < WINDOW_HEIGHT)
	{
		y = (float)(i - start) / (float)(end - start);
		put_pixel(img, x, i, get_pixel((config->textures[ray->direction]), \
		ray->pos_on_wall, y));
	}
	put_img_col_end(img, x, end - 1, config);
}

/*
 This function renders every frame. 
 This function is called in a loop (mlx_hook_loop) 
 so that it will draw to the image for every frame.
 */
void	render_next_frame(void *tmp)
{
	t_config	*config;
	float		d[2];

	config = (t_config *)(tmp);
	d[0] = config->direction[0] * PACE;
	d[1] = config->direction[1] * PACE;
	if (mlx_is_key_down(config->mlx, MLX_KEY_W))
		is_valid_pos(config, config->pos[0] + d[0], config->pos[1] + d[1]);
	if (mlx_is_key_down(config->mlx, MLX_KEY_S))
		is_valid_pos(config, config->pos[0] - d[0], config->pos[1] - d[1]);
	rotate(d, 90);
	if (mlx_is_key_down(config->mlx, MLX_KEY_D))
		is_valid_pos(config, config->pos[0] - d[0], config->pos[1] - d[1]);
	if (mlx_is_key_down(config->mlx, MLX_KEY_A))
		is_valid_pos(config, config->pos[0] + d[0], config->pos[1] + d[1]);
	if (mlx_is_key_down(config->mlx, MLX_KEY_RIGHT))
		rotate_player(config, -ROTATION_SPEED);
	if (mlx_is_key_down(config->mlx, MLX_KEY_LEFT))
		rotate_player(config, ROTATION_SPEED);
	cast_all_lines(config, config->img);
	if (config->draw_minimap)
		draw_minimap(config, config->img);
}
