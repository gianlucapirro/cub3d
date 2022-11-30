/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsetexture.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/26 21:37:36 by gianlucapir   #+#    #+#                 */
/*   Updated: 2022/11/30 12:59:12 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	encode_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	parse_texture(mlx_texture_t **texture, char *line)
{
	line += 3;
	while (*line && *line == ' ')
		line++;
	if (*line == 0)
		exit_error("Error\nNo texture file provided", PARSE_ERROR);
	line[ft_strlen(line) - 1] = 0;
	*texture = mlx_load_png(line);
	return (SUCCES);
}

static int	parse_number(char *str)
{
	int	i;

	str = ft_strtrim(str, " ");
	if (!str)
		exit_error("Error\nMalloc failed", MALLOC_ERROR);
	if (ft_strlen(str) <= 0)
		exit_error("Error\nNot a valid color number", PARSE_ERROR);
	i = -1;
	while (str[++i] && str[i] != '\n')
		if (!ft_isdigit(str[i]))
			exit_error("Error\nNot a valid color number", PARSE_ERROR);
	str[ft_strlen(str)] = '\0';
	i = ft_atoi(str);
	if (i > 255 || i < 0)
		exit_error("Error\nNot a valid color number", PARSE_ERROR);
	free(str);
	return (i);
}

static int	parse_floor_ceiling(int *color, char *line)
{
	char	**split;
	int		i;
	int		rgb[3];

	if (*color != -1)
		exit_error("Error\nDuplicate identifier", PARSE_ERROR);
	line += 2;
	while (*line != 0 && *line == ' ')
		line++;
	split = ft_split(line, ',');
	i = -1;
	if (!split)
		exit_error("Error\nMalloc failed", MALLOC_ERROR);
	if (ft_arr_len(split) != 3 || split[2][0] == '\n')
		exit_error("Error\nNot a valid color code", PARSE_ERROR);
	i = -1;
	while (split[++i])
		rgb[i] = parse_number(split[i]);
	free_array(split);
	*color = encode_rgb(rgb[0], rgb[1], rgb[2]);
	return (SUCCES);
}

// loop over lines read and checks corresponding direction then parses
// texture 
int	parse_textures(t_config *config, t_list_m *linesread, int len)
{
	int		i;
	char	*buffer;

	i = -1;
	while (++i < len)
	{
		list_m_get(linesread, (void **)&buffer, i);
		if (ft_strncmp(buffer, "NO ", 3) == 0)
			parse_texture(&(config->textures[NORTH]), buffer);
		else if (ft_strncmp(buffer, "SO ", 3) == 0)
			parse_texture(&(config->textures[SOUTH]), buffer);
		else if (ft_strncmp(buffer, "WE ", 3) == 0)
			parse_texture(&(config->textures[WEST]), buffer);
		else if (ft_strncmp(buffer, "EA ", 3) == 0)
			parse_texture(&(config->textures[EAST]), buffer);
		else if (ft_strncmp(buffer, "F ", 2) == 0)
			parse_floor_ceiling(&(config->floorcolor), buffer);
		else if (ft_strncmp(buffer, "C ", 2) == 0)
			parse_floor_ceiling(&(config->ceilingcolor), buffer);
		else if (check_empty_line(buffer) == false)
			break ;
		list_m_popi(linesread, (void **)&buffer, i--);
		free(buffer);
	}
	return (SUCCES);
}
