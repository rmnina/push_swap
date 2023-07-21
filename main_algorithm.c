/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 19:44:43 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_chunks(stack **head_a, stack **head_b)
{
    int     chunk_ref;
    int     count;
    
    chunk_ref = 1;
    count = 0;
    while (*head_a)
    {
        if ((*head_a)->chunk != chunk_ref)
        {
            while ((*head_a)->chunk != chunk_ref)
                ft_rotate(head_a, RA);
        }
        if ((*head_a)->chunk == chunk_ref)
        {
            ft_push(head_a, head_b, PA);
            count++;
            if (count % 3 == 0)
                chunk_ref++;
        }
    }
}

void    sort_index(stack **head_a, stack **head_b)
{
    if ((*head_b)->index > (*head_b)->next->index && (*head_b)->next->index > (*head_b)->next->next->index)
        case_321(head_a, head_b);
    else if ((*head_b)->index < (*head_b)->next->index && (*head_b)->next->index > (*head_b)->next->next->index)
    {
        if ((*head_b)->index < (*head_b)->next->next->index)
        {
            ft_swap(head_b, SB);
            case_312(head_a, head_b);
        }
        else
        {
            ft_swap(head_b, SB);
            case_321(head_a, head_b);
        }
    }
    else if ((*head_b)->index > (*head_b)->next->index && (*head_b)->next->index < (*head_b)->next->next->index)
    {
        if ((*head_b)->index < (*head_b)->next->next->index)
            case_213(head_a, head_b);
        else
            case_312(head_a, head_b);
    }
    else if ((*head_b)->index < (*head_b)->next->index && (*head_b)->next->index < (*head_b)->next->next->index)
    {
            ft_swap(head_b, SB);
            case_213(head_a, head_b);
    }
}

void    incomplete_chunks(stack **head_a, stack **head_b)
{
    int     count;
    stack   *i;
        
    i = (*head_b);
    count = 0;   
    while (i->next && i->chunk == i->next->chunk)
    {
        count++;
        i = i->next;
    }
    if (count == 2)    
        sort_index(head_a, head_b);
    else if (count == 1)
    {
        if ((*head_b)->index > i->index)
        {
            ft_push(head_b, head_a, PB);
            ft_push(head_b, head_a, PB);
        }
        else
        {
            ft_swap(head_b, SB);
            ft_push(head_b, head_a, PB);
            ft_push(head_b, head_a, PB);
        }
    }
    else
        ft_push(head_b, head_a, PB);
}


void    main_algorithm(stack **head_a, stack **head_b)
{
    sort_chunks(head_a, head_b);
    while ((*head_b))
    {
        incomplete_chunks(head_a, head_b);
    }
}

// void    opt_b(stack **head_a, stack **head_b)
// {
//     stack   *i;
//     int     max_index;
//     int     count_rotate;
    
//     max_index = ((ft_stacklast(*head_a))->index);
//     i = (*head_b);
//     if (!(*head_b)) 
//         (*head_b) = ft_push(head_a, head_b, PA);
//     else if (((*head_a)->chunk == (*head_b)->chunk) || (*head_a)->chunk > (*head_b)->chunk)
//         ft_push(head_a, head_b, PA);
//     else
//     {
//         while (i->next && (*head_a)->chunk < i->chunk)
//             i = i->next;
//         if (i->index <= (max_index / 2))
//         {
//             count_rotate = 0;
//             while (i != (*head_b))
//             {
//                 ft_rotate(head_b, RB);
//                 count_rotate ++;
//             }
//             ft_push(head_a, head_b, PA);
//             while (count_rotate > 0)
//             {
//                 ft_reverse_rotate(head_b, RRB);
//                 count_rotate --;
//             }
//         }
//         else if (i->index > (max_index / 2))
//         {
//             count_rotate = 1;
//             while (i != (*head_b))
//             {
//                 ft_reverse_rotate(head_b, RRB);
//                 count_rotate ++;
//             }
//             ft_push(head_a, head_b, PA);
//             while (count_rotate > 0)
//             {
//                 ft_reverse_rotate(head_b, RRB);
//                 count_rotate --;
//             }
//         }    
//     }
// }