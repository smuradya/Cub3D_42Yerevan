/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuradya <smuradya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 19:32:28 by smuradya          #+#    #+#             */
/*   Updated: 2023/04/15 17:11:40 by smuradya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedlist.h"
#include "unistd.h"
#include "string.h"

static	void	printer(t_node *node)
{
	write(1, "row ", 4);
	write(1, node->value, strlen(node->value));
	write(1, "\n", 1);
}

void	print_list(t_list *list)
{
	for_each(list, &printer);
}
