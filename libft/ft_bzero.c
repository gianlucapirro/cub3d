/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gpirro <gpirro@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/06 11:05:50 by gpirro        #+#    #+#                 */
/*   Updated: 2021/10/15 17:34:31 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *string, size_t nr)
{
	size_t		i;
	char		*string2;

	string2 = string;
	i = 0;
	while (i < nr)
	{
		string2[i] = '\0';
		i++;
	}
}
