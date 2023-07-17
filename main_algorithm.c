/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/18 01:18:17 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    main_algorithm(stack **head_a, stack **head_b)
{
    stack   *i;
    int     max_index;
    int     count_rotate;
    
    max_index = ((ft_stacklast(*head_a))->index);
    i = (*head_b);
    if (!(*head_b)) 
        (*head_b) = ft_push(head_a, head_b, PA);
    else if (((*head_a)->chunk == (*head_b)->chunk) || (*head_a)->chunk > (*head_b)->chunk)
        ft_push(head_a, head_b, PA);
    else
    {
        while (i->next && (*head_a)->chunk < i->chunk)
            i = i->next;
        if (i->index <= (max_index / 2))
        {
            count_rotate = 0;
            while (i != (*head_b))
            {
                ft_rotate(head_b, RB);
                count_rotate ++;
            }
            ft_push(head_a, head_b, PA);
            while (count_rotate > 0)
            {
                ft_reverse_rotate(head_b, RRB);
                count_rotate --;
            }
        }
        else if (i->index > (max_index / 2))
        {
            count_rotate = 1;
            while (i != (*head_b))
            {
                ft_reverse_rotate(head_b, RRB);
                count_rotate ++;
            }
            ft_push(head_a, head_b, PA);
            while (count_rotate > 0)
            {
                ft_reverse_rotate(head_b, RRB);
                count_rotate --;
            }
        }    
    }
}