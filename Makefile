# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdufour <jdufour@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 12:01:53 by jdufour           #+#    #+#              #
#    Updated: 2024/02/04 23:37:07 by jdufour          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = srcs/error_check.c\
	srcs/indexing.c\
	srcs/instructions.c\
	srcs/instructions2.c\
	srcs/main_algo_cases.c\
	srcs/main_algorithm.c\
	srcs/main.c\
	srcs/small_algorithms.c\
	srcs/utils.c\
	srcs/utils2.c\
	srcs/calc_best_moves.c\
	srcs/calc_best_move_cases.c\

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

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