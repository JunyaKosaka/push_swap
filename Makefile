# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/01 23:49:30 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERFILE = ../push_swap.h ../utils.h

SRCS = main.c \
	./operations/operator_push.c \
	./operations/operator_rotate.c \
	./operations/operator_rrr.c \
	./operations/operator_swap.c \
	./ps_src/push_swap.c \
	./ps_src/ps_sort.c \
	./ps_src/small_size_sort.c \
	./ps_src/block5_sort.c \
	./ps_src/deque_sort.c \
	./ps_src/divide_blocks_dq.c \
	./ps_src/init_stack.c \
	./ps_src/set_wall.c \
	./ps_src/set_border.c \
	./ps_src/divide_ab.c \
	./ps_src/push_a_to_b.c \
	./ps_src/push_b_to_a.c \
	\
	./utils/bubble_sort.c \
	./utils/error_handler.c \
	./utils/free.c \
	./utils/show.c \
	./utils/utils.c \
	./utils/utils2.c \
	./utils/dlst_status.c \
	./utils/dlst_function.c \
	./utils/compress_ans.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ./libft
	cp libft/libft.a $(NAME)
	gcc ${FLAGS} $(SRCS) ./libft/libft.a -o $(NAME)

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C ./libft
	${RM} -rf $(OBJS) $(BNS_OBJS)

fclean : clean
	make fclean -C ./libft
	${RM} -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
