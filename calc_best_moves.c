/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_best_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 15:45:51 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/24 19:12:42 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int close_chunks(stack *head_a, stack *head_b)
{
    if (head_a && head_b && head_a->chunk == head_b->chunk)
        return (1);
    else if (head_a && head_b && head_a->chunk + 1 == head_b->chunk)
        return (1);
    // else if (head_a && head_b && ft_stacksize(head_a) % 3 != 0 && (head_b->chunk == ((ft_stacksize(head_a) / 3) + 1 - (head_a->chunk))))
    //     return (1);
    // else if (head_a && head_b && ft_stacksize(head_a) % 3 == 0 && (head_b->chunk == ((ft_stacksize(head_a) / 3) - (head_a->chunk))))
    //     return (1);
    else
        return (0);
}

int calc_best_move_a(stack *i, stack *head_a)
{
    stack   *j;
    int     moves;

    moves = 0;
    j = head_a;
    while (j && j != i)
    {
        j = j->next;
        moves++;
    }
    // if (moves > (ft_stacksize(head_a) / 2))
    //     moves = ft_stacksize(head_a) - moves;
    return (moves);
}

int calc_best_move_b(stack *i, stack *head_b)
{
    stack   *j;
    int     moves;

    if (!head_b || !head_b->next)
        return (0);
    j = head_b;
    moves = 0;
    while (j && !close_chunks(i, j))
    {
        j = j->next;
        moves++;
    }
    // if (moves > (ft_stacksize(head_b) / 2))
    //     moves = ft_stacksize(head_b) - moves;
    return (moves);
}

void    first_half_a_moves(stack **head_a, stack **head_b, stack **src, stack **dest)
{
    if (first_half((*head_b), (*dest)))
    {
        while ((*src) != (*head_a) && (*dest) != (*head_b))
            ft_rotate_both(head_a, head_b, RR);
        if ((*src) != (*head_a))
            while ((*src) != (*head_a))
                ft_rotate(head_a, RA);
        if ((*dest) != (*head_b))
            while ((*dest) != (*head_b))
                ft_rotate(head_b, RB);
    }
    else
    {
        if ((*src) != (*head_a))
            while ((*src) != (*head_a))
                ft_rotate(head_a, RA);
        if ((*dest) != (*head_b))
            while ((*dest) != (*head_b))
                ft_reverse_rotate(head_b, RRB);
    }
}

void    last_half_a_moves(stack **head_a, stack **head_b, stack **src, stack **dest)
{
    if (!first_half((*head_b), (*dest)))
    {
        while ((*src) != (*head_a) && (*dest) != (*head_b))
            ft_reverse_rotate_both(head_a, head_b, RRR);
        if ((*src) != (*head_a))
            while ((*src) != (*head_a))
                ft_reverse_rotate(head_a, RRA);
        if ((*dest) != (*head_b))
            while ((*dest) != (*head_b))
                ft_reverse_rotate(head_b, RRB);
    }
    else
    {
        if ((*src) != (*head_a))
            while ((*src) != (*head_a))
                ft_reverse_rotate(head_a, RRA);
        if ((*dest) != (*head_b))
            while ((*dest) != (*head_b))
                ft_rotate(head_b, RB);
    }
}
