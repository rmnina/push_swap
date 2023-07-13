/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:54 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/13 18:56:28 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *ft_lstnew_node(int content, int index)
{
	t_node  *new;
	
	index = 0;
	new = (t_node*)malloc(sizeof(*new));
	if (!new)
    	return (NULL);
	new->content = content;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_node  *ft_lstlast_node(t_node *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

t_node  *init_stack_a(char *arg, t_node *head)
{
	t_node  *new;
	t_node	*current;
	int		value;

	current = NULL;
	value = atoi(arg);
	new = ft_lstnew_node(value, 0);
	if (head == NULL)
	{
		head = new;
		current = head;
	}
	else
	{
		current = ft_lstlast_node(head);
		current->next = new;
		current = new;
	}
	return (head);
} 