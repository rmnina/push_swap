/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 15:58:31 by jdufour           #+#    #+#             */
/*   Updated: 2024/02/04 23:36:05 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	set_chunk(t_stack **i, int k)
{
	static int	chunk = 1;

	(*i)->chunk = chunk;
	if (k >= 3 && k % 3 == 0)
		chunk++;
}

void	search_min(t_stack **i, t_stack **j, int *min, int k)
{
	(*j) = (*i)->next;
	while ((*j) != NULL)
	{
		if ((*j)->content == *min)
		{
			(*j)->index = k;
			set_chunk(j, k);
			break ;
		}
		(*j) = (*j)->next;
	}
	*min = (*i)->content;
}

void	move_iterator(t_stack **i, int k, int *min)
{
	(*i)->index = k;
	set_chunk(i, k);
	if ((*i)->next != NULL)
		(*i) = (*i)->next;
	set_new_min(i, min);
}

void	set_new_min(t_stack **i, int *min)
{
	while ((*i))
	{
		if ((*i)->index == 0)
		{
			*min = (*i)->content;
			break ;
		}
		(*i) = (*i)->next;
	}
}

void	init_sorting_indexes(t_stack *head_a)
{
	t_stack		*i;
	t_stack		*j;
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
