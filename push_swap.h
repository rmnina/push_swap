/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:37 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/14 05:45:46 by jdufour          ###   ########.fr       */
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

//MOVES

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

//NODES

typedef struct s_node
{
	int             content;
	int				index;
	int				chunk;
	struct s_node  *next;

}                   stack;

//ERROR CHECKS

void	doubles_check(stack *head_a);
void	basic_checks(char *str);
void	ft_error();

//CREATE STACKS

stack	*init_stack_a(char *value, stack *head_a);


//INDEX STACK A

void	indexing(stack *head_a);
void	search_min(stack **i, stack **j, int *min, int k);
void	move_iterator(stack **i, int k, int *min);
void	set_new_min(stack **i, int *min);


//INSTRUCTIONS

void	write_move(int move);
void	ft_swap(stack **head, int move);
void	ft_push(stack **head_push, stack **head_rec, int move);
void	ft_rotate(stack **head, int move);


//ALGORITHMS

	//SMALL ALGORITHMS

	
	//BIG ALGORITHMS

	
	//OPTI : BEST MOVES CHECKS


//UTILS
int		ft_stacksize(stack *head);
stack  *ft_lstnew_node(int content);
void    ft_stackadd_front(stack **head, stack *new);
stack  *ft_stacklast(stack *last);
void	ft_stackdelone(stack *lst);



void    ft_push_swap(stack *head_a);

#endif