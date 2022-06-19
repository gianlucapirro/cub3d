/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:33:37 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/19 17:11:19 by gianlucapir      ###   ########.fr       */
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
# include <mlx.h>
# include <list.h>
# include <gnl.h>

typedef struct s_config
{
	int	**map;
	int	dimensions[2];
}	t_config;

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
	INVALID_MAP
}	t_status;

typedef enum s_direction
{
	NORH,
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

# define GREY			11184810
# define RED			16711680
# define WHITE			16777215
# define PINK			16727215

void	exit_error(char *msg, int exitcode);
int		is_valid_c(char c);
void	*pcalloc(size_t	size);
void	print_maparray(int dimensions[2], int **map);
int		parse(char *fn, t_config *config);
void	get_fn(char **fn, char *argv[]);
void	error_handling(int argc, t_config *config);

#endif
