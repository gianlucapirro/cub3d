/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 18:34:48 by gianlucapir       #+#    #+#             */
/*   Updated: 2022/06/19 11:49:04 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Tries to open filename (fn). If open fails then it will exit with
 * a corresponding exit message. Else it will parse the whole file into the
 * linked list linesread.
 * 
 * @param fn 
 * @param linesread 
 * @return SUCCES on succes 
 */
int	map2list(char *fn, t_list_m	**linesread)
{
	int			fd;
	char		*buffer;

	fd = open(fn, O_RDONLY);
	if (fd < 0)
		exit_error("Could not open file", OPEN_ERROR);
	*linesread = list_m_init();
	if (!*linesread)
		exit_error("Failed to create list", MALLOC_ERROR);
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (list_m_add(*linesread, (void *)buffer))
			exit_error("Failed to add list", MALLOC_ERROR);
		buffer = get_next_line(fd);
	}
	return (SUCCES);
}

/**
 * @brief Calculates the dimension of the map. It will look for the largest
 * row and the largest column and it will store this value into the int array
 * dimensions.
 * 
 * @param linesread 
 * @param dimensions 
 * @return return SUCCES on succes
 */
int	calc_dimensions(t_list_m *linesread, int dimensions[2])
{
	char	*buffer;
	int		tmp;
	int		len;
	int		i;

	i = 0;
	len = linesread->len;
	dimensions[0] = 0;
	dimensions[1] = len;
	while (i < len)
	{
		list_m_get(linesread, (void **)&buffer, i);
		tmp = ft_strlen(buffer);
		if (ft_strchr(buffer, '\n'))
			tmp--;
		if (tmp > dimensions[0])
			dimensions[0] = tmp;
		i++;
	}
	return (SUCCES);
}

int	get_map_object_type(char c)
{
	if (c == '0')
		return (FLOOR);
	if (c == '1')
		return (WALL);
	if (c == 'N')
		return (START_N);
	if (c == 'W')
		return (START_W);
	if (c == 'S')
		return (START_S);
	if (c == 'E')
		return (START_E);
	if (c == ' ')
		return (EMPTY);
	return (OTHER);
}

/**
 * @brief turns t_list_m into a 2d int array
 * 
 * @param linesread 
 * @param map 
 * @return int 
 */
int	lst2maparray(t_list_m *linesread, int dimensions[2], int ***map)
{
	char	*buffer;
	int		i;
	int		j;

	(*map) = pcalloc(sizeof(int *) * dimensions[1]);
	i = 0;
	while (i < dimensions[1])
	{
		(*map)[i] = pcalloc(sizeof(int) * dimensions[0]);
		list_m_get(linesread, (void **)&buffer, i);
		j = 0;
		while (buffer[j] && buffer[j] != '\n')
		{
			(*map)[i][j] = get_map_object_type(buffer[j]);
			j++;
		}
		i++;
	}
	return (0);
}

//TODO: Make a config struct where we can place the map
int	parse(char *fn)
{
	t_list_m	*linesread;
	int			dimensions[2];
	int			**map;

	map2list(fn, &linesread);
	calc_dimensions(linesread, dimensions);
	lst2maparray(linesread, dimensions, &map);
	list_m_free(linesread, 1);
	print_maparray(dimensions, map);
	return (0);
}
