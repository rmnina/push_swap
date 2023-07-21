/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 19:44:46 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push_swap(stack **head_a, stack **head_b, int argc)
{
	(void) argc;
	init_sorting_indexes(*head_a);
	if (argc == 4)
		three_values_algo(head_a);
	if (argc == 6)
		five_values_algo(head_a, head_b);
	else
		main_algorithm(head_a, head_b);
}

void print_list_content(stack *head_a, void (*print_func)(int)) 
{
    stack *current = head_a;

    while (current != NULL) {
        print_func(current->content);
        current = current->next;
    }
    ft_printf("\n");
}

void print_list_chunk(stack *head_a, void (*print_func)(int)) 
{
    stack *current = head_a;

    while (current != NULL) {
        print_func(current->chunk);
        current = current->next;
    }
    ft_printf("\n");
}

void print_list_index(stack *head_a, void (*print_func)(int)) 
{
    stack *current = head_a;

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
	stack	*head_a;
	stack	*head_b;
	
	if (argc < 2)
		ft_error();
	i = 1;
	head_a = NULL;
	head_b = NULL;
	doubles_check(argv);
	while (i < argc)
	{
		basic_checks(argv[i]);
		head_a = init_stack_a(argv[i], head_a);
		i++;
	}
	ft_push_swap(&head_a, &head_b, argc);
	ft_printf("content =\n");
	print_list_content(head_a, print_int);
	ft_stackclear(&head_a);
	return (0);
}