/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithms.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:56:47 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/17 18:41:24 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_values_algo(stack **head_a)
{
    if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
    {
        ft_rotate(head_a, RA);
        ft_swap(head_a, SA);
    }
    else if ((*head_a)->index < (*head_a)->next->index && (*head_a)->next->index > (*head_a)->next->next->index)
    {
        if ((*head_a)->index < (*head_a)->next->next->index)
        {
            ft_reverse_rotate(head_a, RRA);
            ft_swap(head_a, SA);
        }
        else
            ft_reverse_rotate(head_a, RRA);
    }
    else if ((*head_a)->index > (*head_a)->next->index && (*head_a)->next->index < (*head_a)->next->next->index)
    {
        if ((*head_a)->index < (*head_a)->next->next->index)
            ft_swap(head_a, SA);
        else
            ft_rotate(head_a, RA);
    }
}