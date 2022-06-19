/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:30:45 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:13 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_get(t_list_m *list, void **val, int pos)
{
	t_node_m	*elem;
	int			i;

	if (list == NULL || list->head == NULL || pos >= list->len || pos < 0)
		return (1);
	elem = list->head;
	i = 0;
	while (i < pos)
	{
		elem = elem->next;
		i++;
	}
	*val = elem->value;
	return (0);
}
