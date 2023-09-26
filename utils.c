/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:31:26 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:22:32 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *last)
{
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

t_stack	*ft_lstnew_node(int content, int index, int chunk)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = content;
	new->index = index;
	new->chunk = chunk;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_back(t_stack **head, t_stack *new)
{
	t_stack	*last;

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

int	ft_stacksize(t_stack *head)
{
	int	i;

	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	return (i);
}

void	ft_stackdelone(t_stack *lst)
{
	if (!lst)
		return ;
	lst->next = NULL;
	free(lst);
}
