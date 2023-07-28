/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:19:18 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 21:51:40 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_both(stack **head_a, stack **head_b, int move)
{
	ft_rotate(head_a, 0);
	ft_rotate(head_b, 0);
	write_move(move);
}

void	ft_reverse_rotate_both(stack **head_a, stack **head_b, int move)
{
	ft_reverse_rotate(head_a, 0);
	ft_reverse_rotate(head_b, 0);
	write_move(move);
}