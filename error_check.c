/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:45 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/13 23:30:51 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int basic_checks(char *str)
{
	int i;
	long long int value;

	i = 0;
	value = 0;
	if (str == NULL || str[i] == '\n' || str[0] == '\0')
	{
		ft_putstr("Error null");
		return (0);
	}
	if (ft_strlen(str) > 11)
	{
		ft_putstr("Error size");
		return (0);
	}
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			ft_putstr("Error int\n");
			return (0);
		}
		i++;
	}
	value = ft_atoi(str);
	if (!(value >= -2147483648 && value <= 2147483647))
	{
		ft_putstr("Error atoi\n");
		return (0);
	}
	return (1);
}

int	doubles_check(t_node *head)
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
			{
				ft_putstr("Error doubles\n");
				return (0);
			}
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}