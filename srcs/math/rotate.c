/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:09:41 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/24 19:16:40 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	rotate(float vec[2], float deg)
{
	float	tmpx;
	float	tmpy;
	float	deg_rad;

	deg_rad = deg_to_rad(deg);
	tmpx = vec[0] * cos(deg_rad) + vec[1] * -sin(deg_rad);
	tmpy = vec[0] * sin(deg_rad) + vec[1] * cos(deg_rad);
	vec[0] = tmpx;
	vec[1] = tmpy;
	return (SUCCES);
}
