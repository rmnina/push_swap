/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:18:10 by jdufour           #+#    #+#             */
/*   Updated: 2024/02/04 23:36:48 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*pos;

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

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int	first_half(int moves)
{
	if (moves >= 0)
		return (1);
	return (0);
}
