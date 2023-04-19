/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:30:28 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/15 17:11:32 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLIST_H
# define LINKEDLIST_H

#include "stdio.h"
#include "stdlib.h"

typedef struct s_node		t_node;

struct s_node
{
	char	*value;
	t_node	*next;
	t_node	*prev;
};

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		count;
}	t_list;

// linkedlist.c
t_list	*new_list(void);
void	add(t_list *list, t_node *node);
t_node	*new_node(char *value);

// linkedlist_utils.c
void	for_each(t_list *list, void (*func)(t_node *));

// linkedlist_free.c
void	free_list(t_list *list);

// linkedlist_printer.c
void	print_list(t_list *list);

#endif
