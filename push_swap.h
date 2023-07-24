/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:37 by jdufour           #+#    #+#             */
/*   Updated: 2023/07/21 23:34:32 by jdufour          ###   ########.fr       */
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

void	doubles_check(char **argv);
void	basic_checks(char *str);
void	ft_error();

//CREATE STACKS

stack	*init_stack_a(char *arg, stack *head_a);
int		is_sorted(stack *head_b);

//INDEX STACK A

void	init_sorting_indexes(stack *head_a);
void	search_min(stack **i, stack **j, int *min, int k);
void	move_iterator(stack **i, int k, int *min);
void	set_new_min(stack **i, int *min);


//INSTRUCTIONS

void	write_move(int move);
void	ft_swap(stack **head, int move);
stack	*ft_push(stack **head_push, stack **head_rec, int move);
void	ft_rotate(stack **head, int move);
void	ft_reverse_rotate(stack **head, int move);

//ALGORITHMS

	//SMALL ALGORITHMS
void    three_values_algo(stack **head_a);
void    minmax_val(stack **head_a, stack **head_b);
void    five_values_algo(stack **head_a, stack **head_b);
	
	//BIG ALGORITHMS
void    sort_chunks(stack **head_a, stack **head_b);
void    sort_index(stack **head_a, stack **head_b);
void    main_algorithm(stack **head_a, stack **head_b);
void    send_chunks_back(stack **head_a, stack **head_b);

		//CASES
void    case_321(stack **head_a, stack **head_b);
void    case_213(stack **head_a, stack **head_b);
void    case_312(stack **head_a, stack **head_b);

	//OPTI : BEST MOVES CHECKS
void    best_moves_check(stack **head_a, int pos);
int   	opposite_chunk(stack **head_a, int chunk_max, int chunk_ref);
void    reorder_stack_b(stack **head_b);

//UTILS
int		ft_stacksize(stack *head);
stack  *ft_lstnew_node(int content, int index, int chunk);
void    ft_stackadd_front(stack **head, stack *new);
stack  *ft_stacklast(stack *last);
void	ft_stackdelone(stack *lst);
void    ft_stackclear(stack **lst);


void    ft_push_swap(stack **head_a, stack **head_b, int argc);

#endif