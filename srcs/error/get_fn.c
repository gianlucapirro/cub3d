/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:19:21 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/19 16:34:33 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_fn(char **fn, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
		(*fn) = argv[1];
	else
		exit_error("Could not open map", OPEN_ERROR);
	close(fd);
}
