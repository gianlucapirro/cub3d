/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:09 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/22 17:11:10 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	alloc_2d_array(int w, int h, int size, void ***array)
{
	int	height;

	*array = pcalloc(sizeof(void *) * h);
	height = 0;
	while (height < h)
	{
		(*array)[height] = pcalloc(size * w);
		height++;
	}
	return (SUCCES);
}
