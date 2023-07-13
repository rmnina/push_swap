/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:37 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 00:45:47 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include "libft/libft.h"

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_node
{
	int             content;
	int				index;
	struct s_node  *next;

}                   t_node;

void	write_move(int move);
t_node	*init_stack_a(char *value, t_node *head);
t_node  *ft_lstnew_node(int content, int index);
void	basic_checks(char *str);
void	doubles_check(t_node *head);
void    ft_push_swap(t_node *head);
void	indexing(t_node *head);
void	search_min(t_node **i, t_node **j, int *min, int k);
void	move_iterator(t_node **i, int k, int *min);
void	set_new_min(t_node **i, int *min);
void	ft_error();


#endif