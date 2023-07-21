/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algo_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:12:55 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 19:44:40 by jdufour          ###   ########.fr       */
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

