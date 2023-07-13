/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:45 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 00:46:04 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(1); 
}

void basic_checks(char *str)
{
	int i;
	long long int value;

	i = 0;
	value = 0;
	if (str == NULL || str[i] == '\n' 
		|| str[0] == '\0' || ft_strlen(str) > 11)
		ft_error();
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		i++;
	}
	value = ft_atoi(str);
	if (!(value >= INT_MIN && value <= INT_MAX))
		ft_error();
}

void	doubles_check(t_node *head)
{
	t_node	*i;
	t_node	*j;
	
	i = head;
	j = NULL;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->content == j->content)
				ft_error();
			j = j->next;
		}
		i = i->next;
	}
}