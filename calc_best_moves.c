/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:45:51 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:39:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	good_sup_chunk_check(t_stack **head_b, t_stack **i)
{
	t_stack	*j;
	int		chunk_ref;

	j = *head_b;
	chunk_ref = (*i)->chunk;
	while (chunk_ref > 0)
	{
		while (j)
		{
			if (j->chunk == chunk_ref)
				return (chunk_ref);
			j = j->next;
		}
		j = *head_b;
		chunk_ref--;
	}
	if (chunk_ref == 0)
	{
		while (j)
			my_function_was_too_long(&j, &chunk_ref);
	}
	return (chunk_ref);
}

int	calc_best_move_a(t_stack **i, t_stack **head_a)
{
	t_stack	*j;
	int		moves;

	moves = 0;
	j = (*head_a);
	while (j && j != (*i))
	{
		if (ft_stacksize(*head_a) % 2 == 0)
		{
			if (moves == ft_stacksize(*head_a) / 2)
				moves *= -1;
			moves++;
		}
		else
		{
			if (moves == ft_stacksize(*head_a) / 2)
				moves *= -1;
			else
				moves++;
		}
		j = j->next;
	}
	return (moves);
}

int	calc_best_move_b(t_stack **i, t_stack **head_b)
{
	t_stack	*j;
	int		moves;

	j = (*head_b);
	moves = 0;
	while (j)
	{
		if (j->chunk == good_sup_chunk_check(head_b, i))
			return (moves);
		if (ft_stacksize(*head_b) % 2 == 0)
		{
			if (moves == ft_stacksize(*head_b) / 2)
				moves *= -1;
			moves++;
		}
		else
		{
			if (moves == ft_stacksize(*head_b) / 2)
				moves *= -1;
			else
				moves++;
		}
		j = j->next;
	}
	return (moves);
}

void	first_half_a_moves(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b)
{
	if (first_half(*moves_b))
		first_half_a_and_b(head_a, head_b, moves_a, moves_b);
	else
	{
		if ((*moves_a > 0))
		{
			while ((*moves_a > 0))
			{
				ft_rotate(head_a, RA);
				*moves_a -= 1;
			}
		}
		if (*moves_b < 0)
		{
			while (*moves_b < 0)
			{
				ft_reverse_rotate(head_b, RRB);
				*moves_b += 1;
			}
		}
	}
}

void	last_half_a_moves(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b)
{
	if (!first_half(*moves_b))
		last_half_a_and_b(head_a, head_b, moves_a, moves_b);
	else
	{
		if ((*moves_a < 0))
		{
			while ((*moves_a < 0))
			{
				ft_reverse_rotate(head_a, RRA);
				*moves_a += 1;
			}
		}
		if (*moves_b > 0)
		{
			while (*moves_b > 0)
			{
				ft_rotate(head_b, RB);
				*moves_b -= 1;
			}
		}
	}
}
