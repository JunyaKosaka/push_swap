# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/12/27 18:12:35 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERFILE = push_swap.h

SRCS = push_swap.c \
	solve.c set_border.c push_a_to_b.c push_b_to_a.c\
	./operator/operator_swap.c ./operator/operator_rrr.c  \
	./operator/operator_rotate.c ./operator/operator_push.c \
	./utils/dlst_operator.c ./utils/dlst_info.c\
	./utils/show.c ./utils/compress_ans.c ./utils/utils.c\
	./utils/bubble_sort.c divide.c main.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ./libft
	make $(FLAGS) -C ./printf
	cp libft/libft.a $(NAME)
	cp printf/libftprintf.a $(NAME)
	gcc ${FLAGS} $(SRCS) ./libft/libft.a ./printf/libftprintf.a -o $(NAME)

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C ./libft
	make clean -C ./printf
	${RM} -rf $(OBJS) $(BNS_OBJS)

fclean : clean
	make fclean -C ./libft
	make fclean -C ./printf
	${RM} -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
