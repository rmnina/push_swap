/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:55 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 22:28:39 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    case_321(stack **head_a, stack **head_b)
{
	ft_push(head_b, head_a, PA);
	ft_push(head_b, head_a, PA);
	ft_push(head_b, head_a, PA);
}

void    case_213(stack **head_a, stack **head_b)
{
	ft_push(head_b, head_a, PA);
	ft_swap(head_b, SB);
	ft_push(head_b, head_a, PA);
	ft_swap(head_a, SA);
	ft_push(head_b, head_a, PA);
}

void    case_312(stack **head_a, stack **head_b)
{
	ft_push(head_b, head_a, PA);
	ft_swap(head_b, SB);
	ft_push(head_b, head_a, PA);
	ft_push(head_b, head_a, PA);
}

void    send_chunks_back_case_1(stack **head_a, stack **head_b, stack **i)
{
	if ((*head_b)->index > (*i)->index)
		{
			ft_push(head_b, head_a, PA);
			ft_push(head_b, head_a, PA);
		}
		else
		{
			ft_swap(head_b, SB);
			ft_push(head_b, head_a, PA);
			ft_push(head_b, head_a, PA);
		}
}

void    cases_push_node(stack **head_a, stack **head_b, int *moves_a, int *moves_b)
{
	if ((*head_a)->next && ((*head_b)->chunk == (*head_a)->next->chunk))
	{
		ft_swap(head_a, SA);
		ft_push(head_a, head_b, PB);
	}
	else if (*moves_a == 0 && *moves_b == 0)
		ft_push(head_a, head_b, PB);
	else
	{
		if (first_half(*moves_a))
			first_half_a_moves(head_a, head_b, moves_a, moves_b);
		else
			last_half_a_moves(head_a, head_b, moves_a, moves_b);
		ft_push(head_a, head_b, PB);
	}
}