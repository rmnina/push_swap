/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 22:01:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_index(stack **head_a, stack **head_b)
{
	if ((*head_b)->index > (*head_b)->next->index && (*head_b)->next->index > (*head_b)->next->next->index)
		case_321(head_a, head_b);
	else if ((*head_b)->index < (*head_b)->next->index && (*head_b)->next->index > (*head_b)->next->next->index)
	{
		if ((*head_b)->index < (*head_b)->next->next->index)
		{
			ft_swap(head_b, SB);
			case_312(head_a, head_b);
		}
		else
		{
			ft_swap(head_b, SB);
			case_321(head_a, head_b);
		}
	}
	else if ((*head_b)->index > (*head_b)->next->index && (*head_b)->next->index < (*head_b)->next->next->index)
	{
		if ((*head_b)->index < (*head_b)->next->next->index)
			case_213(head_a, head_b);
		else
			case_312(head_a, head_b);
	}
	else if ((*head_b)->index < (*head_b)->next->index && (*head_b)->next->index < (*head_b)->next->next->index)
	{
		ft_swap(head_b, SB);
		case_213(head_a, head_b);
	}
}

void    push_node(stack **head_a, stack **head_b, int stacksize)
{
	int moves_a;
	int moves_b;
	stack *i;

	i = (*head_a);
	moves_a = calc_best_move_a(&i, head_a);
	moves_b = calc_best_move_b(&i, head_b, stacksize);
	while (i)
	{
		if (ft_abs(calc_best_move_a(&i, head_a)) + ft_abs(calc_best_move_b(&i, head_b, stacksize)) < ft_abs(moves_a) + ft_abs(moves_b))
		{
			moves_a = calc_best_move_a(&i, head_a);
			moves_b = calc_best_move_b(&i, head_b, stacksize);
			ft_printf("i content %d\n", i->content);
			ft_printf("good chunk check %d\n", good_chunk_check(head_b, &i, stacksize));
		}
		i = i->next;
	}
	ft_printf("move a = %d\n", moves_a);
	ft_printf("move_b = %d\n", moves_b);
	cases_push_node(head_a, head_b, &moves_a, &moves_b);
}

void    reorder_stack_b(stack **head_b)
{
    stack   *i;
    int     count;

    count = 0; 
    i = (*head_b);
    while (i && i->chunk != 1)
    {
        i = i->next;
        count++;
    }
    if (count < ft_stacksize(*head_b) / 2)
        while (count + 3 > 0)
        {
            ft_rotate(head_b, RB);
            count--;
        }
    else
    {
        count = (ft_stacksize((*head_b)) - count - 3);
        while (count > 0)
        {
            ft_reverse_rotate(head_b, RRB);
            count--;
        }
    }
}

void    send_chunks_back(stack **head_a, stack **head_b)
{
	int     count;
	stack   *i;

	i = (*head_b);
	count = 0;
	while (i->next && i->chunk == i->next->chunk)
	{
		count++;
		i = i->next;
	}
	if (count == 2)
		sort_index(head_a, head_b);
	else if (count == 1)
		send_chunks_back_case_1(head_a, head_b, &i);
	else
		ft_push(head_b, head_a, PA);
}

void    main_algorithm(stack **head_a, stack **head_b)
{
	int stacksize;

	stacksize = ft_stacksize(*head_a);
	if (!(*head_b))
		ft_push(head_a, head_b, PB);
	while (*head_a)
	{
		ft_printf("list content \n");
		print_list_content((*head_a));
		ft_printf("b list content \n");
		print_list_content((*head_b));
		push_node(head_a, head_b, stacksize);
	}
	ft_printf("final b list content \n");
	print_list_content((*head_b));
	reorder_stack_b(head_b);
	ft_printf("reordered b list content \n");
	print_list_content((*head_b));
	while ((*head_b))
		send_chunks_back(head_a, head_b);
}