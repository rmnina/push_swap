/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:54 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 19:44:35 by jdufour          ###   ########.fr       */
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
		ft_stackadd_front(&head_a, new);
	return (head_a);
}

int	is_sorted(stack *head_b)
{
	stack	*i;

	i = head_b;
	while (i)
	{
		if (i->chunk < i->next->chunk)
			return (0);
	}
	return (1);
}