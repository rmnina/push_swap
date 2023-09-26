/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:11:11 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_stack **head_a, t_stack **head_b)
{
	if ((*head_b)->index > (*head_b)->next->index && \
	(*head_b)->next->index > (*head_b)->next->next->index)
		case_321(head_a, head_b);
	else if ((*head_b)->index < (*head_b)->next->index && \
	(*head_b)->next->index > (*head_b)->next->next->index)
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
	else if ((*head_b)->index > (*head_b)->next->index && \
	(*head_b)->next->index < (*head_b)->next->next->index)
	{
		if ((*head_b)->index < (*head_b)->next->next->index)
			case_213(head_a, head_b);
		else
			case_312(head_a, head_b);
	}
	else if ((*head_b)->index < (*head_b)->next->index && \
	(*head_b)->next->index < (*head_b)->next->next->index)
	{
		ft_swap(head_b, SB);
		case_213(head_a, head_b);
	}
}

void	push_node(t_stack **head_a, t_stack **head_b)
{
	int		moves_a;
	int		moves_b;
	t_stack	*i;

	i = (*head_a);
	moves_a = calc_best_move_a(&i, head_a);
	moves_b = calc_best_move_b(&i, head_b);
	while (i)
	{
		if (ft_abs(calc_best_move_a(&i, head_a)) + \
		ft_abs(calc_best_move_b(&i, head_b)) < ft_abs(moves_a) + \
		ft_abs(moves_b))
		{
			moves_a = calc_best_move_a(&i, head_a);
			moves_b = calc_best_move_b(&i, head_b);
		}
		i = i->next;
	}
	cases_push_node(head_a, head_b, &moves_a, &moves_b);
}

void	reorder_stack_b(t_stack **head_b)
{
	t_stack	*i;
	int		count;

	count = 0;
	i = (*head_b);
	while (i && i->chunk != 1)
	{
		i = i->next;
		count++;
	}
	if (count < ft_stacksize(*head_b) / 2)
	{
		while (count + 3 > 0)
		{
			ft_rotate(head_b, RB);
			count--;
		}
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

void	send_chunks_back(t_stack **head_a, t_stack **head_b)
{
	int		count;
	t_stack	*i;

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

void	main_algorithm(t_stack **head_a, t_stack **head_b)
{
	if (!(*head_b))
		ft_push(head_a, head_b, PB);
	while (*head_a)
		push_node(head_a, head_b);
	reorder_stack_b(head_b);
	while ((*head_b))
		send_chunks_back(head_a, head_b);
}
