/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:51:30 by jdufour           #+#    #+#             */
/*   Updated: 2024/02/04 23:36:16 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

t_stack	*ft_push(t_stack **head_push, t_stack **head_rec, int move)
{
	t_stack	*temp;

	temp = (*head_push);
	(*head_push) = (*head_push)->next;
	temp->next = (*head_rec);
	(*head_rec) = temp;
	write_move(move);
	return ((*head_rec));
}

void	ft_swap(t_stack **head, int move)
{
	t_stack	*temp;

	if (!(*head) || !((*head)->next))
		return ;
	temp = (*head);
	(*head) = (*head)->next;
	temp->next = (*head)->next;
	(*head)->next = temp;
	write_move(move);
}

void	ft_rotate(t_stack **head, int move)
{
	t_stack	*last;
	t_stack	*temp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = ft_stacklast((*head));
	temp = (*head);
	last->next = temp;
	*head = temp->next;
	temp->next = NULL;
	write_move(move);
}

void	ft_reverse_rotate(t_stack **head, int move)
{
	t_stack	*last;
	t_stack	*second_to_last;

	last = (*head);
	second_to_last = NULL;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_to_last = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	second_to_last->next = NULL;
	write_move(move);
}
