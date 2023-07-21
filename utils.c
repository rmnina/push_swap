/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:31:26 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 19:44:54 by jdufour          ###   ########.fr       */
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

void    ft_stackadd_front(stack **head, stack *new)
{
    if (!head || !new)
        return ;
    new->next = *head;
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

void    ft_stackclear(stack **lst)
{
    stack  *pos;
    
    pos = *lst;
    if (!lst)
        return ;
    while (pos)
    {
        pos = (*lst)->next;
        ft_stackdelone(*lst);
        *lst = pos;
    }
    *lst = NULL;
}