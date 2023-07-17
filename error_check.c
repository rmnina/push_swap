/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:50:45 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/17 18:40:14 by jdufour          ###   ########.fr       */
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
	if (str == NULL || str[0] == '\0' || ft_strlen(str) > 11)
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

void	doubles_check(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				ft_error();
			j++;
		}
		i++;
	}
}