/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:32:54 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/15 17:11:25 by smuradya         ###   ########.fr       */
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

t_node	*new_node(char *value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (value)
		node->value = strdup(value);
	else
		node->value = NULL;
	node->next = NULL;
	return (node);
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