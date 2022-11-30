/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_fn.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/19 16:19:21 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/11/30 15:22:40 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


int	can_be_opened(char *fn)
{
	int	fd;

	fd = open(fn, O_RDWR);
	if (fd < 0)
	{
		if (errno == EISDIR)
			return (0);
		fd = open(fn, O_RDONLY);
		if (fd < 0)
			return (0);
	}
	close(fd);
	return (1);
}


void	get_fn(char **fn, char *argv[])
{
	int	fd;

	fd = open(argv[1], O_RDWR);
	if (fd < 0)
	{

		(*fn) = argv[1];
	}
	else
		exit_error("Could not open map", OPEN_ERROR);
	close(fd);
}
