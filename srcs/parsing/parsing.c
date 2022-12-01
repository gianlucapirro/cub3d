/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/18 18:34:48 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/11/30 17:03:30 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

/**
 * @brief Tries to open filename (fn). If open fails then it will exit with
 * a corresponding exit message. Else it will parse the whole file line by line
 * into the linked list linesread.
 * 
 * @param fn 
 * @param linesread 
 * @return SUCCES on succes 
 */
int	file2list(char *fn, t_list_m	**linesread)
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

/**
 * @brief Checks what type of map object the char c is. 
 * Floor, Wall, Start_N/S/W/E, Empty, Other
 * 
 * @param c 
 * @return Map object type of char c
 */
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
 * @brief loops till the end of linesread, for every char in the str
 * of each read line it will put the value in the map. Does it in reverse
 * because bottom left screen is not 0.0, in math it is
 * 
 * @param linesread 
 * @param map 
 * @return int 
 */
int	lst2maparray(t_list_m *linesread, int dimensions[2], int ***map)
{
	char	*buffer;
	int		y;
	int		x;

	(*map) = pcalloc(sizeof(int *) * dimensions[1]);
	y = 0;
	while (y < dimensions[1])
	{
		(*map)[dimensions[1] - 1 - y] = pcalloc(sizeof(int) * dimensions[0]);
		list_m_get(linesread, (void **)&buffer, y);
		x = 0;
		while (buffer[x] && buffer[x] != '\n')
		{
			(*map)[dimensions[1] - 1 - y][x] = get_map_object_type(buffer[x]);
			x++;
		}
		y++;
	}
	return (0);
}

/**
 * @brief Parse all necesarry information out of fn into
 * the config struct
 * 
 * @param fn 
 * @param config 
 * @return int 
 */
int	parse(char *fn, t_config *config)
{
	t_list_m	*linesread;

	config->textures[NORTH] = NULL;
	config->textures[SOUTH] = NULL;
	config->textures[WEST] = NULL;
	config->textures[EAST] = NULL;
	config->ceilingcolor = -1;
	config->floorcolor = -1;
	file2list(fn, &linesread);
	parse_textures(config, linesread, linesread->len);
	if (config->textures[NORTH] == NULL || config->textures[SOUTH] == NULL || \
		config->textures[WEST] == NULL || config->textures[EAST] == NULL || \
		config->ceilingcolor == -1 || config->floorcolor == -1)
		exit_error("Error\nNot all values provided in map", PARSE_ERROR);
	calc_dimensions(linesread, config->dimensions);
	lst2maparray(linesread, config->dimensions, &config->map);
	list_m_free(linesread, 1);
	return (0);
}
