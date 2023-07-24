/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/24 15:43:27 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_same_chunks(stack **head_a, stack **head_b, int *chunk_ref, int *count)
{
        ft_push(head_a, head_b, PA);
        *count += 1;
        if (*count == 3)
        {
            *chunk_ref+=1;
            *count = 0;
        }
}

void    sort_opposite_chunk(stack **head_a, stack **head_b, int *opposite_chunk_ref, int *count2)
{
            ft_push(head_a, head_b, PA);
            ft_rotate(head_b, RB);
            *count2 += 1;
            if (*count2 == 3)
            {
                *opposite_chunk_ref-=1;
                *count2 = 0;
            }
}

void    sort_chunks(stack **head_a, stack **head_b)
{
    int     chunk_ref;
    int     count;
    int     pos;
    stack   *i;
    
    chunk_ref = 1;
    count = 0;
    while (*head_a)
    {
        if ((*head_a)->chunk != chunk_ref)
        {
            i = (*head_a);
            pos = 0;
            while (i && i->chunk != chunk_ref)
            {
                i = i->next;
                pos++;
            }
            while ((*head_a)->chunk != chunk_ref)
                best_moves_check(head_a, pos);
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

// void    sort_chunks(stack **head_a, stack **head_b)
// {
//     int     chunk_ref;
//     int     opposite_chunk_ref;
//     int     count = 0;
//     int     count2 = 0;
//     int     pos;
//     stack   *i;
    
//     chunk_ref = 1;
//     opposite_chunk_ref = ft_stacksize(*head_a) / 3;
//     if ((ft_stacksize(*head_a)) % 3 != 0)
//         opposite_chunk_ref +=1;
//     while (*head_a)
//     {
//         if ((*head_a)->chunk != opposite_chunk_ref || (*head_a)->chunk != chunk_ref)
//         {
//             i = (*head_a);
//             pos = 0;
//             while (i && i->chunk != opposite_chunk_ref && (*head_a)->chunk != chunk_ref)
//             {
//                 i = i->next;
//                 pos++;
//             }
//             while ((*head_a)->chunk != opposite_chunk_ref && (*head_a)->chunk != chunk_ref)
//                 best_moves_check(head_a, pos);
//         }
//         if ((*head_a)->chunk == opposite_chunk_ref)
//             sort_opposite_chunk(head_a, head_b, &opposite_chunk_ref, &count2);
//         if ((*head_a)->chunk == chunk_ref)
//             sort_same_chunks(head_a, head_b, &chunk_ref, &count);
//     }
//     reorder_stack_b(head_b); 
// }

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

void    send_chunks_back(stack **head_a, stack **head_b)
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
        send_chunks_back(head_a, head_b);
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