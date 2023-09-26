/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:05 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:13:35 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack_a(char *arg, t_stack *head_a)
{
	t_stack		*new;
	int			value;

	value = atoi(arg);
	new = ft_lstnew_node(value, 0, 0);
	if (head_a == NULL)
		head_a = new;
	else
		ft_stackadd_back(&head_a, new);
	return (head_a);
}

int	is_sorted(t_stack *head_a)
{
	t_stack	*i;

	i = head_a;
	while (i->next != NULL)
	{
		if (i->content > i->next->content)
			return (0);
		i = i->next;
	}
	return (1);
}

void	ft_push_swap(t_stack **head_a, t_stack **head_b, int argc)
{
	if (!is_sorted(*head_a))
	{
		init_sorting_indexes(*head_a);
		if (argc == 4)
			three_values_algo(head_a);
		if (argc == 6)
			five_values_algo(head_a, head_b);
		else
			main_algorithm(head_a, head_b);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*head_a;
	t_stack	*head_b;

	if (argc < 2)
		return (0);
	i = 1;
	head_a = NULL;
	head_b = NULL;
	doubles_check(argv);
	while (i < argc)
	{
		basic_checks(argv[i]);
		head_a = init_stack_a(argv[i], head_a);
		i++;
	}
	ft_push_swap(&head_a, &head_b, argc);
	if (!(is_sorted(head_a)))
		ft_error();
	ft_stackclear(&head_a);
	return (0);
}
