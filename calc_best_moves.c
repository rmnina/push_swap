/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:45:51 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 20:45:14 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int close_chunks(stack *head_a, stack *head_b)
// {
//     if (head_a && head_b && head_a->chunk == head_b->chunk)
//         return (1);
//     else if (head_a && head_b && head_a->chunk + 1 == head_b->chunk)
//         return (1);
//     // else if (head_a && head_b && ft_stacksize(head_a) % 3 != 0 && (head_b->chunk == ((ft_stacksize(head_a) / 3) + 1 - (head_a->chunk))))
//     //     return (1);
//     // else if (head_a && head_b && ft_stacksize(head_a) % 3 == 0 && (head_b->chunk == ((ft_stacksize(head_a) / 3) - (head_a->chunk))))
//     //     return (1);
//     else
//         return (0);
// }

int    good_chunk_check(stack **head_b, stack **i, int stacksize)
{
    stack   *j;
    int     chunk_ref;
    int     opposite_chunk;
    
    j = *head_b;
    chunk_ref = (*i)->chunk;
    opposite_chunk = stacksize + 1 - chunk_ref;
    while (chunk_ref > 0)
    {
        while (j)
        {
            if (j->chunk == chunk_ref || j->chunk == opposite_chunk)
                return (chunk_ref);
            j = j->next;
        }
        j = *head_b;
        chunk_ref--;
    }
    if (chunk_ref == 0)
        while (j)
        {
            if (j->chunk > chunk_ref)
                chunk_ref = j->chunk;
            j = j->next;
        }
    return (chunk_ref);
}

int calc_best_move_a(stack **i, stack **head_a)
{
    stack   *j;
    int     moves;

    moves = 0;
    j = (*head_a);
    while (j && j != (*i))
    {
        if (ft_stacksize(*head_a) % 2 == 0)
        {
            if (moves == ft_stacksize(*head_a) / 2)
                moves *= -1;
            moves++;
        }
        else
        {
            if (moves == ft_stacksize(*head_a) / 2)
                moves *= -1;
            else
                moves++;
        } 
        j = j->next;
    }
    return (moves);
}

int calc_best_move_b(stack **i, stack **head_b, int stacksize)
{
    stack   *j;
    int     moves;

    j = (*head_b);
    moves = 0;
    while (j)
    {
        if (j->chunk == good_chunk_check(head_b, i, stacksize))
            return (moves);
        if (ft_stacksize(*head_b) % 2 == 0)
        {
            if (moves == ft_stacksize(*head_b) / 2)
                moves *= -1;
            moves++;
        }
        else
        {
            if (moves == ft_stacksize(*head_b) / 2)
                moves *= -1;
            else
                moves++;
        } 
        j = j->next;      
    }
    return (moves);
}

void    first_half_a_moves(stack **head_a, stack **head_b, int *moves_a, int *moves_b)
{
    if (first_half(*moves_b))
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
    else
    {
        if ((*moves_a > 0))
            while ((*moves_a > 0))
            {
                ft_rotate(head_a, RA);
                *moves_a -= 1;
            }
        if (*moves_b < 0)
            while (*moves_b < 0)
            {
                ft_reverse_rotate(head_b, RRB);
                *moves_b += 1;
            }
    }
}


void    last_half_a_moves(stack **head_a, stack **head_b, int *moves_a, int *moves_b)
{
    if (!first_half(*moves_b))
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
    else
    {
        if ((*moves_a < 0))
            while ((*moves_a < 0))
            {
                ft_reverse_rotate(head_a, RRA);
                *moves_a += 1;
            }
        if (*moves_b > 0)
            while (*moves_b > 0)
            {
                ft_rotate(head_b, RB);
                *moves_b -= 1;
            }
    }
}
