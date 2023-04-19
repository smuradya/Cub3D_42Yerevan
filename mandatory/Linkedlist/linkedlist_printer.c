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
