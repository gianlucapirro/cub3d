/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:12:14 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/24 19:16:55 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/*
 Takes a degree as a double and turns it into a radian
 */
float	deg_to_rad(float deg)
{
	return ((PI / 180) * deg);
}
