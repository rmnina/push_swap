/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:56:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 21:22:39 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_values_algo(stack **head_a)
{
	if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index) //3 2 1
	{
		ft_rotate(head_a, RA);
		ft_swap(head_a, SA);
	}
	else if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index) // 1 3 2
		{
			ft_reverse_rotate(head_a, RRA);
			ft_swap(head_a, SA);
		}
		else // 2 3 1
			ft_reverse_rotate(head_a, RRA);
	}
	else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index) // 2 1 3
			ft_swap(head_a, SA);
		else // 3 1 2
			ft_rotate(head_a, RA);
	}
}

void    minmax_val(stack **head_a, stack **head_b)
{
	if ((*head_b)->content < (*head_a)->content)
	{
		ft_push(head_b, head_a, PA);
		ft_push(head_b, head_a, PA);
		ft_rotate(head_a, RA);
	}
	else
	{
		ft_push(head_b, head_a, PA);
		ft_rotate(head_a, RA);  
		ft_push(head_b, head_a, PA);      
	}
}

void    five_values_algo(stack **head_a, stack **head_b)
{
	stack   *i;
	int     pos;

	while (ft_stacksize((*head_a)) != 3)
	{
		i = (*head_a);
		pos = 1;
		if (i->index != 1 && i->index != 5)
			while (i->index != 1 && i->index != 5)
			{
				i = i->next;
				pos++;
			}
		if (pos < 3)
			while ((*head_a)->index != i->index)
				ft_rotate(head_a, RA);
		else if (pos >= 3)
			while ((*head_a)->index != i->index)
				ft_reverse_rotate(head_a, RRA);
		ft_push(head_a, head_b, PB);
	}
	three_values_algo(head_a);
	minmax_val(head_a, head_b);
}