/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:20:43 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/22 17:26:28 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	print_matrix(t_matrix a)
{
	int	x;
	int	y;

	y = -1;
	while (++y < a.h)
	{
		x = -1;
		while (++x < a.w)
			printf("%d	", a.mat[y][x]);
		printf("\n");
	}
	return (SUCCES);
}

int	matrix_calloc(int w, int h, t_matrix **m)
{
	*m = (t_matrix *)pcalloc(sizeof(t_matrix));
	alloc_2d_array(w, h, sizeof(float), (*m)->mat);
}
