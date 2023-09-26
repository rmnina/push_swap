/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:32:37 by jdufour           #+#    #+#             */
/*   Updated: 2023/09/24 19:39:12 by jdufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "libft/libft.h"

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

//STRUCT

typedef struct s_node
{
	int				content;
	int				index;
	int				chunk;
	struct s_node	*next;

}					t_stack;

//ERROR CHECKS

void	doubles_check(char **argv);
void	basic_checks(char *str);
void	ft_error(void);

//INIT STACK A

t_stack	*init_stack_a(char *arg, t_stack *head_a);
void	init_sorting_indexes(t_stack *head_a);
void	search_min(t_stack **i, t_stack **j, int *min, int k);
void	move_iterator(t_stack **i, int k, int *min);
void	set_new_min(t_stack **i, int *min);

//INSTRUCTIONS

void	write_move(int move);
void	ft_swap(t_stack **head, int move);
t_stack	*ft_push(t_stack **head_push, t_stack **head_rec, int move);
void	ft_rotate(t_stack **head, int move);
void	ft_reverse_rotate(t_stack **head, int move);
void	ft_rotate_both(t_stack **head_a, t_stack **head_b, int move);
void	ft_reverse_rotate_both(t_stack **head_a, t_stack **head_b, int move);

//ALGORITHMS

	//SMALL ALGORITHMS
void	three_values_algo(t_stack **head_a);
void	minmax_val(t_stack **head_a, t_stack **head_b);
void	five_values_algo(t_stack **head_a, t_stack **head_b);

	//BIG ALGORITHMS
void	push_node(t_stack **head_a, t_stack **head_b);
void	cases_push_node(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b);
void	sort_index(t_stack **head_a, t_stack **head_b);
void	send_chunks_back(t_stack **head_a, t_stack **head_b);
void	reorder_stack_b(t_stack **head_b);
void	main_algorithm(t_stack **head_a, t_stack **head_b);

	//CASES
void	case_321(t_stack **head_a, t_stack **head_b);
void	case_213(t_stack **head_a, t_stack **head_b);
void	case_312(t_stack **head_a, t_stack **head_b);
void	send_chunks_back_case_1(t_stack **head_a, \
t_stack **head_b, t_stack **i);

	//OPTI : BEST MOVES CHECKS
void	last_half_a_moves(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b);
void	first_half_a_moves(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b);
void	my_function_was_too_long(t_stack **j, int *chunk_ref);
int		calc_best_move_a(t_stack **i, t_stack **head_a);
int		calc_best_move_b(t_stack **i, t_stack **head_b);
int		good_sup_chunk_check(t_stack **head_b, t_stack **i);

	//BEST MOVES CHECKS CASES
void	first_half_a_and_b(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b);
void	last_half_a_and_b(t_stack **head_a, t_stack **head_b, \
int *moves_a, int *moves_b);

//UTILS
int		ft_stacksize(t_stack *head);
t_stack	*ft_lstnew_node(int content, int index, int chunk);
void	ft_stackadd_back(t_stack **head, t_stack *new);
t_stack	*ft_stacklast(t_stack *last);
void	ft_stackdelone(t_stack *lst);
void	ft_stackclear(t_stack **lst);
int		ft_abs(int n);
int		is_sorted(t_stack *head_b);
int		first_half(int moves);

//MAIN

void	ft_push_swap(t_stack **head_a, t_stack **head_b, int argc);

#endif