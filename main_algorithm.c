/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 18:41:34 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/24 18:52:20 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int first_half(stack *head, stack *pos)
{
    stack   *i;
    int     count;

    i = head;
    count = 0;
    while (i && i != pos)
    {
        i = i->next;
        count++;
    }
    if (count <= ft_stacksize(head) / 2)
        return (1);
    return (0);
}

void    push_node(stack **head_a, stack **head_b)
{
    int     moves_a;
    int     moves_b;
    stack   *i;
    stack   *src;
    stack   *dest;
    
    i = (*head_a);
    src = (*head_a);
    dest = (*head_b);
    moves_a = calc_best_move_a(i, (*head_b));
    moves_b = calc_best_move_b(i, (*head_a));
    while (i)
    {
        i = i->next;
        if (calc_best_move_a(i, (*head_a)) + calc_best_move_b(i, (*head_b)) < moves_a + moves_b)
        {
            moves_a = calc_best_move_a(i, (*head_a));
            moves_b = calc_best_move_b(i, (*head_b));
            src = i;
        }
    }
    while (dest->next && !close_chunks(src, dest))
        dest = dest->next;
    if (first_half((*head_a), dest))
        first_half_a_moves(head_a, head_b, &src, &dest);
    else 
        last_half_a_moves(head_a, head_b, &src, &dest);
    ft_push(head_a, head_b, PB);
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
            ft_push(head_b, head_a, PA);
            ft_push(head_b, head_a, PA);
        }
        else
        {
            ft_swap(head_b, SB);
            ft_push(head_b, head_a, PA);
            ft_push(head_b, head_a, PA);
        }
    }
    else
        ft_push(head_b, head_a, PA);
}

void    main_algorithm(stack **head_a, stack **head_b)
{
    if (!(*head_b))
        ft_push(head_a, head_b, PB);
    while (*head_a)
    {
        ft_printf("list content \n");
        print_list_content((*head_a), print_int);
        push_node(head_a, head_b);
    }
    reorder_stack_b(head_b);
    while ((*head_b))
        send_chunks_back(head_a, head_b);
}