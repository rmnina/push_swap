/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:31:26 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 21:22:52 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack  *ft_stacklast(stack *last)
{
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

stack  *ft_lstnew_node(int content, int index, int chunk)
{
	stack  *new;

	new = (stack*)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->chunk = chunk;
	new->next = NULL;
	return (new);
}

void    ft_stackadd_back(stack **head, stack *new)
{
	stack  *last;

	if (!new)
		return ;
	if (*head)
	{
		last = ft_stacklast(*head);
		last->next = new;
	}
	else
		*head = new;
}

int    ft_stacksize(stack *head)
{
	int i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void    ft_stackdelone(stack *lst)
{
	if (!lst)
		return ;
	lst->next = NULL;
	free(lst);
}