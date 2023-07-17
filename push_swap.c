/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/15 15:49:12 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_swap(stack *head_a)
{
	indexing(head_a);
}

void print_list(stack *head_a, void (*print_func)(int)) 
{
    stack *current = head_a;

    while (current != NULL) {
        print_func(current->content);
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
	stack	*head_a;

	if (argc < 2)
		ft_error();
	i = 1;
	head_a = NULL;
	while (i < argc)
	{
		basic_checks(argv[i]);
		head_a = init_stack_a(argv[i], head_a);
		i++;
	}
	doubles_check(head_a);
	tri_test(&head_a);
	print_list(head_a, print_int);
	return (0);
}