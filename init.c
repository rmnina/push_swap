/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:54 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/28 19:37:52 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack  *init_stack_a(char *arg, stack *head_a)
{
	stack  		*new;
	int			value;

	value = atoi(arg);
	new = ft_lstnew_node(value, 0, 0);
	if (head_a == NULL)
		head_a = new;
	else
		ft_stackadd_back(&head_a, new);
	return (head_a);
}

int	is_sorted(stack *head_a)
{
	stack	*i;

	i = head_a;
	while (i->next != NULL)
	{
		if (i->content > i->next->content)
			return (0);
		i = i->next;
	}
	return (1);
}