/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:31:09 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:26 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static int	list_m_insert2(t_list_m *list, int pos, t_node_m *elem)
{
	t_node_m	*buff;
	int			i;

	if (list->len == pos + 1)
	{
		list->tail->next = elem;
		elem->prev = list->tail;
		list->tail = elem;
		return (0);
	}
	buff = list->head;
	i = 0;
	while (i < pos)
	{
		i++;
		buff = buff->next;
	}
	elem->next = buff;
	elem->prev = buff->prev;
	buff->prev = elem;
	elem->prev->next = elem;
	return (0);
}

int	list_m_insert(t_list_m *list, void *value, int pos)
{
	t_node_m	*elem;

	if (list == NULL)
		return (1);
	if (list->len < pos || pos < 0)
		return (1);
	elem = (t_node_m *)malloc(sizeof(t_node_m));
	if (elem == NULL)
		return (1);
	elem->value = value;
	list->len += 1;
	if (pos == 0)
	{
		elem->prev = NULL;
		elem->next = list->head;
		list->head = elem;
		if (list->tail == NULL)
			list->tail = elem;
		else
			elem->next->prev = elem;
		return (0);
	}
	return (list_m_insert2(list, pos, elem));
}
