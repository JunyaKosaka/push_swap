# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/03 19:07:23 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERFILE = ../includes/push_swap.h

SRCS = \
	main.c \
	push_swap.c \
	ps_sort.c \
	small_size_sort.c \
	block5_sort.c \
	deque_sort.c \
	divide_blocks_dq.c \
	set_wall.c \
	set_border.c \
	divide_ab.c \
	push_a_to_b.c \
	push_b_to_a.c \
	check_b.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ../utils
	gcc ${FLAGS} $(SRCS) ../utils/libutil.a -o $(NAME)

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C ../libft
	make clean -C ../utils
	${RM} -rf $(OBJS)

fclean : clean
	make fclean -C ../libft
	make fclean -C ../utils
	${RM} -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus