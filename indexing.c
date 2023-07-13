/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:58:31 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/13 22:56:56 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_nodesize(t_node *lst)
{
    int i;

    i = 0;
    while (lst)
    {
        i++;
        lst = lst->next;
    }
    return (i);
}

void	search_min(t_node **i, t_node **j, int *min, int k)
{
	(*j) = (*i)->next;
	while ((*j) != NULL)
	{
		if ((*j)->content == *min)
		{
			(*j)->index = k;
				break;
		}
		(*j) = (*j)->next;
	}
	*min = (*i)->content;
}

void	move_iterator(t_node **i, int k, int *min)
{
	(*i)->index = k;
	if ((*i)->next != NULL)
		(*i) = (*i)->next;
	set_new_min(i, min);
}

void set_new_min(t_node **i, int *min)
{
	while ((*i))
	{
		if ((*i)->index == 0)
		{
			*min = (*i)->content;
			break;
		}
		(*i) = (*i)->next;
	}
}

void	indexing(t_node *head)
{
	t_node		*i;
	t_node		*j;
	int			min;
	int			k;

	i = head;
	j = NULL;
	min = head->content;
	k = 1;
	while (k <= ft_nodesize(head))
	{
		j = i->next;
		while (j)
		{
			if (j->content < min && j->index == 0)
				min = j->content;
			j = j->next;
		}
		if (i->content == min)
			move_iterator(&i, k, &min);
		else
			search_min(&i, &j, &min, k);
		k++;
	}
}