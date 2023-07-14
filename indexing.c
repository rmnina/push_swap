/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:58:31 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 04:33:38 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_min(stack **i, stack **j, int *min, int k)
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

void	move_iterator(stack **i, int k, int *min)
{
	(*i)->index = k;
	if ((*i)->next != NULL)
		(*i) = (*i)->next;
	set_new_min(i, min);
}

void set_new_min(stack **i, int *min)
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

void	indexing(stack *head_a)
{
	stack		*i;
	stack		*j;
	int			min;
	int			k;

	i = head_a;
	j = NULL;
	min = head_a->content;
	k = 1;
	while (k <= ft_stacksize(head_a))
	{
		j = i->next;
		while (j)
		{
			if (j->content < min && !(j->index))
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