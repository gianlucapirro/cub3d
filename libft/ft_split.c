/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/12 18:51:28 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/10/15 17:36:08 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	string_amount(char const *s, char c)
{
	int	i;
	int	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	next_string(char **string, int *string_len, char c)
{
	int	i;

	*string += *string_len;
	*string_len = 0;
	i = 0;
	while (**string && **string == c)
		(*string)++;
	while ((*string)[i])
	{
		if ((*string)[i] == c)
			return ;
		(*string_len)++;
		i++;
	}
}

static char	**malloc_free(char **twodarray)
{
	int	i;

	i = 0;
	while (twodarray[i])
	{
		free(twodarray[i]);
		i++;
	}
	free(twodarray);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**twodarray;
	char			*string;
	int				string_len;
	int				nb_strs;
	int				i;

	if (!s)
		return (NULL);
	nb_strs = string_amount(s, c);
	twodarray = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!twodarray)
		return (NULL);
	i = 0;
	string = (char *)s;
	string_len = 0;
	while (i < nb_strs)
	{
		next_string(&string, &string_len, c);
		twodarray[i] = malloc(sizeof(char) * (string_len + 1));
		if (!twodarray[i])
			return (malloc_free(twodarray));
		ft_strlcpy(twodarray[i++], string, string_len + 1);
	}
	twodarray[i] = 0;
	return (twodarray);
}
