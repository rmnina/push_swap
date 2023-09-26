/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:56:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:19:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_values_algo(t_stack **head_a)
{
	if ((*head_a)->index > (*head_a)->next->index && \
	(*head_a)->next->index > (*head_a)->next->next->index)
	{
		ft_rotate(head_a, RA);
		ft_swap(head_a, SA);
	}
	else if ((*head_a)->index < (*head_a)->next->index && \
	(*head_a)->next->index > (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index)
		{
			ft_reverse_rotate(head_a, RRA);
			ft_swap(head_a, SA);
		}
		else
			ft_reverse_rotate(head_a, RRA);
	}
	else if ((*head_a)->index > (*head_a)->next->index && \
	(*head_a)->next->index < (*head_a)->next->next->index)
	{
		if ((*head_a)->index < (*head_a)->next->next->index)
			ft_swap(head_a, SA);
		else
			ft_rotate(head_a, RA);
	}
}

void	minmax_val(t_stack **head_a, t_stack **head_b)
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

void	five_values_algo(t_stack **head_a, t_stack **head_b)
{
	t_stack	*i;
	int		pos;

	while (ft_stacksize((*head_a)) != 3)
	{
		i = (*head_a);
		pos = 1;
		if (i->index != 1 && i->index != 5)
		{
			while (i->index != 1 && i->index != 5)
			{
				i = i->next;
				pos++;
			}
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
