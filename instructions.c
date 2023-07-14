/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:51:30 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 05:45:34 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_move(int move)
{
	if (move == SA)
		ft_putstr("sa\n");
	if (move == SB)
		ft_putstr("sb\n");
	if (move == SS)
		ft_putstr("ss\n");
	if (move == PA)
		ft_putstr("pa\n");
	if (move == PB)
		ft_putstr("pb\n");
	if (move == RA)
		ft_putstr("ra\n");
	if (move == RB)
		ft_putstr("rb\n");
	if (move == RR)
		ft_putstr("rr\n");
	if (move == RRA)
		ft_putstr("rra\n");
	if (move == RRB)
		ft_putstr("rrb\n");
	if (move == RRR)
		ft_putstr("rrr\n");
}

void	ft_swap(stack **head, int move)
{
	stack	*temp;

	temp = (*head);
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	write_move(move);
}

void	ft_push(stack **head_push, stack **head_rec, int move)
{
	stack	*temp;

	temp = (*head_push);
	(*head_push) = (*head_push)->next;
	temp->next = (*head_rec);
	(*head_rec) = temp;
	write_move(move);
}

void	ft_rotate(stack **head, int move)
{
	stack	*temp;
	stack	*last;
	
	temp = (*head);
	last = ft_stacklast(&head);
	(*head) = last;
	last->next = temp;
	write_move(move);
}