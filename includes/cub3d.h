/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:33:37 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/30 13:48:13 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <time.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>
# include "libft.h"
# include <stdbool.h>
# include <mlx.h>
# include <list.h>
# include <gnl.h>
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		w;
	int		h;
}		t_data;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_config
{
	t_data	texture;
	int		**map;
	int		dimensions[2];
	int		player_size[2];
	int		block_size[2];
	float	direction[2];
	float	pos[2];
	void	*mlx;
	void	*mlx_win;
}	t_config;

typedef struct s_matrix
{
	float	**mat;
	int		w;
	int		h;
}	t_matrix;

typedef struct s_camera
{
	t_matrix	*internal;
	t_matrix	*external;
}	t_camera;

typedef struct s_ray
{
	float	distance;
	int		direction;
	float	pos_on_wall;
	int		x;
	int		y;
	float	real_x;
	float	real_y;
}		t_ray;

typedef enum s_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef enum s_status
{
	SUCCES,
	FAILED,
	OPEN_ERROR,
	CLOSE_ERROR,
	PARSE_ERROR,
	MLX_ERROR,
	MALLOC_ERROR,
	ARGUMENT_ERROR,
	INVALID_MAP,
	NOT_FOUND
}	t_status;

typedef enum s_direction
{
	NORTH,
	WEST,
	SOUTH,
	EAST
}	t_direction;

typedef enum s_objects
{
	EMPTY,
	FLOOR,
	WALL,
	START_N,
	START_W,
	START_S,
	START_E,
	OTHER
}	t_objects;

typedef enum e_keys
{
	ARROW_R	= 124,
	ARROW_L	= 123,
	ARROW_U	= 125,
	ARROW_D	= 126,
	PAGE_U	= 116,
	PAGE_D	= 121,
	PLUS	= 24,
	ESC		= 53,
	MIN		= 27,
	Q		= 12,
	W		= 13,
	E		= 14,
	A		= 0,
	S		= 1,
	D		= 2
}	t_keys;

// typedef enum e_keys
// {
// 	ARROW_R	= 65363,
// 	ARROW_L	= 65361,
// 	ARROW_U	= 65361,
// 	ARROW_D	= 65363,
// 	PAGE_U	= 116,
// 	PAGE_D	= 121,
// 	PLUS	= 24,
// 	ESC		= 53,
// 	MIN		= 27,
// 	Q		= 12,
// 	W		= 119,
// 	E		= 14,
// 	A		= 97,
// 	S		= 115,
// 	D		= 100, 
// }	t_keys;

typedef enum e_textures
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_textures;

# define GREY			0x00808080
# define RED			0x00FF0000
# define WHITE			0x00FFFFFF
# define PINK			0x00FF1493
# define BLACK			0x00000000

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define PI 3.14159
# define FOV 60.0

# define PACE	0.25
# define ROTATION_SPEED	10

# define INFINITY_INT 1000000
//libft+

void	exit_error(char *msg, int exitcode);
void	*pcalloc(size_t	size);
float	deg_to_rad(float deg);

//utils

int		is_valid_c(char c);
int		is_start_pos(char c);
int		encode_rgb(u_int8_t r, u_int8_t g, u_int8_t b);

//parsing

int		get_start_pos(t_config *config);
int		parse(char *fn, t_config *config);
void	get_fn(char **fn, char *argv[]);
void	print_maparray(int dimensions[2], int **map);

//error

void	error_handling(int argc, t_config *config);

//minilibx+

void	put_pixel(t_data *data, int x, int y, int color);
int		render_next_frame(void *tmp);

//drawing

int		draw_minimap(t_config *config, t_data *img_data);
int		draw_wall(t_config *c, t_data *img_d, int wall[3], int color);
int		draw_minimap_cross(t_config *conf, t_data *img_data, float pos[2]);
int		draw_rectangle(int pos[2], int dimensions[2], \
		t_data *img_data, int color);
void	draw_line(t_data *data, t_point *p1, t_point *p2, int color);
void	draw_cross(t_data *img_data, int pos[2], int size);

//events

int		key_press(int keycode, t_config	*config);

/******************************************************************************/
/* Checks if the wall exist, if so set the correct position of the ray on     */
/* the wall. It flips coordinates of NORTH and WEST to make sure the          */
/* texture is rendered correctly (position must be left to right)             */
/*                                                                            */
/* @param t_config* config:                                         	      */
/*      Configuration struct                                                  */
/* @param float inter[2]:                                                     */
/*      Point of intersection                                                 */
/* @param int wall[3]:                                                        */
/*      Coordinates of wall and the directions it faces                       */
/* @param int ray[4]:                                                         */
/*      Result is put into this variable, the x, y, direction, ray position on*/
/*      wall                                                                  */
/* @return (t_bool):                                                          */
/*      SUCCES if wall was found FAILED if not                                */
/******************************************************************************/
int		get_wall(t_config *config, float inter[2], int wall[3], t_ray *ray);

int		rotate(float vec[2], float deg);
int		cast(t_config *config, t_ray *ray, float direction[2], float angle);
int		draw_minimap_line(t_config *config, t_data *img_data, float start[2], float end[2]);

#endif
