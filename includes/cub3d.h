/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 09:33:37 by hthomas           #+#    #+#             */
/*   Updated: 2022/06/18 01:26:05 by gianlucapir      ###   ########.fr       */
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
# include "mlxlinux.h"
# include "libft.h"

# define AZERTY			0
# define OPEN_ERROR		-1
# define CLOSE_ERROR	-2
# define PARSE_ERROR	-3
# define MLX_ERROR		-4
# define MALLOC_ERROR	-5

# define THETA			0.05
# define SPEED_MOVE		0.15
# define CEILING_COLOR	6185465
# define FLOOR_COLOR	2105376
# define FOV			0.66

# define GREY			11184810
# define RED			16711680
# define WHITE			16777215
# define PINK			16727215

# define MAX_WIDE		3840
# define NB_TEXTURES	5
# define WHITE_SPACES	" \t"
# define NB_ELEM_RES	3
# define NB_ELEM_TEX	2
# define NB_ELEM_COLOR	2

# define SOUTH			0
# define EAST			1
# define NORTH			2
# define WEST			3
# define SPRITE			4

#endif
