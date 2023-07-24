/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:55 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 23:52:19 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    case_321(stack **head_a, stack **head_b)
{
    ft_push(head_b, head_a, PB);
    ft_push(head_b, head_a, PB);
    ft_push(head_b, head_a, PB);
}

void    case_213(stack **head_a, stack **head_b)
{
    ft_push(head_b, head_a, PB);
    ft_swap(head_b, SB);
    ft_push(head_b, head_a, PB);
    ft_swap(head_a, SA);
    ft_push(head_b, head_a, PB);
}

void    case_312(stack **head_a, stack **head_b)
{
    ft_push(head_b, head_a, PB);
    ft_swap(head_b, SB);
    ft_push(head_b, head_a, PB);
    ft_push(head_b, head_a, PB);
}

void    best_moves_check(stack **head_a, int pos)
{
    int middle;

    middle = ft_stacksize((*head_a)) / 2;
    if (pos < middle)
        ft_rotate(head_a, RA);
    else if (pos >= middle)
        ft_reverse_rotate(head_a, RRA);
}

void    reorder_stack_b(stack **head_b)
{
    while (ft_stacklast((*head_b))->chunk != 1)
        ft_reverse_rotate(head_b, RRB);
}