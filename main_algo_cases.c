/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:55 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/25 01:16:21 by jdufour          ###   ########.fr       */
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
    int     count;

    count = 0; 
    i = (*head_b);
    while (i && i->chunk != 1)
    {
        i = i->next;
        count++;
    }
    ft_printf("count = %d, half stack = %d\n", count, ft_stacksize(*head_b) / 2);
    if (count < ft_stacksize(*head_b) / 2)
        while (count + 3 > 0)
        {
            ft_rotate(head_b, RB);
            count--;
        }
    else
        while (count - 3 > 0)
        {
            ft_reverse_rotate(head_b, RRB);
            count--;
        }
}