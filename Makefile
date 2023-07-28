# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 12:01:53 by jdufour           #+#    #+#              #
#    Updated: 2023/07/28 21:50:53 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = error_check.c\
	indexing.c\
	instructions.c\
	instructions2.c\
	main_algo_cases.c\
	main_algorithm.c\
	push_swap.c\
	small_algorithms.c\
	utils.c\
	utils2.c\
	calc_best_moves.c\
	calc_best_move_cases.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

RM = rm -rfv

all: ${NAME}

${NAME} : libft/libft.a ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -L libft -lft -o ${NAME}

libft/libft.a:
	make -C libft

clean:
	${RM} ${OBJS}
	make clean -C libft

fclean: clean
	${RM} ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re