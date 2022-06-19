/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list_m_popi.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jsiegers <jsiegers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/29 16:30:45 by jsiegers      #+#    #+#                 */
/*   Updated: 2022/05/11 11:36:37 by jsiegers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

static t_node_m	*pop_middle(t_list_m *list, int pos)
{
	int			i;
	t_node_m	*elem;
	t_node_m	*buff;

	i = 0;
	elem = list->head;
	while (i < pos)
	{
		elem = elem->next;
		i++;
	}
	buff = elem->prev;
	buff->next = elem->next;
	elem->next->prev = buff;
	return (elem);
}

int	list_m_popi(t_list_m *list, void **val, int pos)
{
	t_node_m	*elem;

	if (list == NULL || list->head == NULL || list->len < pos + 1 || pos < 0)
		return (1);
	list->len -= 1;
	if (pos == 0)
	{
		if (list->len == 0)
			list->tail = NULL;
		elem = list->head;
		list->head = elem->next;
		list->head->prev = NULL;
	}
	else if (pos == list->len)
	{
		elem = list->tail;
		list->tail = elem->prev;
		list->tail->next = NULL;
	}
	else
		elem = pop_middle(list, pos);
	*val = elem->value;
	free(elem);
	return (0);
}
