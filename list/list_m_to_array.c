/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_to_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:31:00 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:57 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_to_array(t_list_m *list, void ***arr)
{
	int			i;
	t_node_m	*elem;

	if (arr == 0)
		return (1);
	*arr = (void **)malloc(sizeof(void *) * list->len);
	if (*arr == 0)
		return (1);
	i = 0;
	elem = list->head;
	while (elem)
	{
		(*arr)[i] = elem->value;
		i++;
		elem = elem->next;
	}
	return (i);
}
