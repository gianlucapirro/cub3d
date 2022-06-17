/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/11 21:50:20 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/10/15 17:36:46 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	if (s1 && s1)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen((char *) s1) + \
		ft_strlen((char *) s2) + 1));
		i = 0;
		if (new == NULL)
			return (NULL);
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			new[ft_strlen((char *) s1) + i] = s2[i];
			i++;
		}
		new[ft_strlen((char *) s1) + i] = '\0';
		return (new);
	}
	return (NULL);
}
