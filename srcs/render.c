/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/17 13:35:24 by gpirro        #+#    #+#                 */
/*   Updated: 2022/11/30 14:35:03 by gpirro        ########   odam.nl         */
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
		mlx_put_pixel(img, x, i, config->ceilingcolor);
	return (0);
}

static int	put_img_col_end(mlx_image_t *img, int x, int i, t_config *config)
{
	while (++i < WINDOW_HEIGHT)
		mlx_put_pixel(img, x, i, config->floorcolor);
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
		mlx_put_pixel(img, x, i, get_pixel((config->textures[ray->direction]), \
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

	config = (t_config *)(tmp);
	cast_all_lines(config, config->img);
	// draw_minimap(config, config->img)
}
