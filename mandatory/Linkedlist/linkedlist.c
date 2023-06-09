/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhakob2 <anhakob2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:32:54 by smuradya          #+#    #+#             */
/*   Updated: 2023/06/11 23:42:51 by anhakob2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include "string.h"

t_list	*new_list(void)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	list->count = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

void	add(t_list *list, t_node *node)
{
	node->prev = list->tail;
	if (list->count == 0)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	list->count++;
}
