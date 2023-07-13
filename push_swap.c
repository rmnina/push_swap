/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 00:47:13 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_swap(t_node *head)
{
	indexing(head);
}

void print_list(t_node *head, void (*print_func)(int)) 
{
    t_node *current = head;

    while (current != NULL) {
        print_func(current->index);
        current = current->next;
    }
    ft_printf("\n");
}

void print_int(int content) 
{
    int value = content;
    ft_printf("%d ", value);
}

int main(int argc, char **argv)
{
	int i;
	t_node	*head;

	if (argc < 2)
		ft_error();
	i = 1;
	head = NULL;
	while (i < argc)
	{
		basic_checks(argv[i]);
		head = init_stack_a(argv[i], head);
		i++;
	}
	doubles_check(head);
	ft_push_swap(head);
	print_list(head, print_int);
	return (0);
}