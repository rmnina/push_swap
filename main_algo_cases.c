/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:55 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/24 18:19:07 by jdufour          ###   ########.fr       */
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

void    reorder_stack_b(stack **head_b)
{
    stack   *i;
    while (i && i->chunk != 1)
        i = i->next;
    if (first_half((*head_b), i))
        while (ft_stacklast((*head_b))->chunk != 1)
            ft_rotate(head_b, RB);
    else
        while (ft_stacklast((*head_b))->chunk != 1)
            ft_reverse_rotate(head_b, RRB);
}