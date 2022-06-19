/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 17:45:57 by jsiegers      #+#    #+#                 */
/*   Updated: 2021/10/21 17:45:57 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <gnl.h>

static char	*set_remainder(char *remainder, char *buffer, int i_read)
{
	char	*tmp;

	if (i_read < 0)
		exit(0);
	buffer[i_read] = '\0';
	if (remainder == 0 && i_read == 0)
		return (0);
	if (remainder == 0)
	{
		return (ft_strdup(buffer));
	}
	tmp = ft_strjoin(remainder, buffer);
	free(remainder);
	return (tmp);
}

static char	*not_found(char **remainder, int i_read, int fd)
{
	char	*tmp;

	if (i_read < 1024)
	{
		tmp = ft_strdup(*remainder);
		free(*remainder);
		*remainder = 0;
		return (tmp);
	}
	return (get_next_line(fd));
}

static char	*reset_remainder(char *remainder, char *pos)
{
	char	*tmp;

	tmp = remainder;
	remainder = ft_strdup(pos + 1);
	free(tmp);
	return (remainder);
}

static char	*check_remainder_null(char **remainder, char *res)
{
	if (*remainder == 0)
	{
		free(res);
		return (NULL);
	}
	else if (**remainder == 0)
	{
		free(*remainder);
		*remainder = 0;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		buffer[1025];
	int			i_read;
	char		*pos;
	char		*res;

	if (remainder == NULL || ft_strchr(remainder, '\n') == 0)
	{
		i_read = read(fd, buffer, 1024);
		remainder = set_remainder(remainder, buffer, i_read);
		if (remainder == 0)
			return (0);
	}
	pos = ft_strchr(remainder, '\n');
	if (pos == 0)
		return (not_found(&remainder, i_read, fd));
	res = malloc((pos - remainder + 2) * sizeof(char));
	if (res == 0)
		return (0);
	ft_strlcpy(res, remainder, (pos - remainder + 2));
	remainder = reset_remainder(remainder, pos);
	return (check_remainder_null(&remainder, res));
}
