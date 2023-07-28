/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_move_cases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:39:32 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 21:45:55 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    first_half_a_and_b(stack **head_a, stack **head_b, int *moves_a, int *moves_b)
{
	while ((*moves_a > 0) && (*moves_b > 0))
		{
			ft_rotate_both(head_a, head_b, RR);
			*moves_a -= 1;
			*moves_b -= 1;
		}
		if ((*moves_a > 0))
			while ((*moves_a > 0))
			{
				ft_rotate(head_a, RA);
				*moves_a -= 1;
			}
		if ((*moves_b > 0))
			while ((*moves_b > 0))
			{
				ft_rotate(head_b, RB);
				*moves_b -= 1;
			}
}

void    last_half_a_and_b(stack **head_a, stack **head_b, int *moves_a, int *moves_b)
{
	while ((*moves_a < 0) && (*moves_b < 0))
		{
			ft_reverse_rotate_both(head_a, head_b, RRR);
			*moves_a += 1;
			*moves_b += 1;
		}
		if ((*moves_a < 0))
			while ((*moves_a < 0))
			{
				ft_reverse_rotate(head_a, RRA);
				*moves_a += 1;
			}
		if ((*moves_b < 0))
			while ((*moves_b < 0))
			{
				ft_reverse_rotate(head_b, RRB);
				*moves_b += 1;
			}
}