/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_m_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsiegers <jsiegers@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 16:31:33 by jsiegers          #+#    #+#             */
/*   Updated: 2022/01/02 12:39:27 by jsiegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int	list_m_add(t_list_m *list, void *value)
{
	t_node_m	*elem;
	t_node_m	*buff;

	if (list == NULL)
		return (1);
	elem = (t_node_m *)malloc(sizeof(t_node_m));
	if (elem == NULL)
		return (1);
	buff = list->tail;
	elem->value = value;
	elem->next = NULL;
	list->tail = elem;
	list->len += 1;
	if (buff == NULL)
	{
		list->head = elem;
		elem->prev = NULL;
		return (0);
	}
	buff->next = elem;
	elem->prev = buff;
	return (0);
}
