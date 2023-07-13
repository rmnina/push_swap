/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/13 19:46:57 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_swap(t_node *head)
{
	indexing(head);
}

void print_list(t_node *head, void (*print_func)(int)) {
    t_node *current = head;

    while (current != NULL) {
        print_func(current->index);
        current = current->next;
    }
    printf("\n");
}

void print_int(int content) {
    int value = content;
    printf("%d ", value);
}

int main(int argc, char **argv)
{
	int i;
	t_node	*head;

	if (argc < 2)
	{
		ft_putstr("Error argc\n");
		return (0);
	}
	i = 1;
	head = NULL;
	while (i < argc)
	{
		if (!basic_checks(argv[i]))
			return (0);
		head = init_stack_a(argv[i], head);
		i++;
	}
	if (!doubles_check(head))
			return (0);
	ft_push_swap(head);
	print_list(head, print_int);
	
}