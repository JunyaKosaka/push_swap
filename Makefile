# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/12/27 17:37:27 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERFILE = push_swap.h

SRCS = push_swap.c push_swap_utils.c push_swap_utils_dlist.c \
	solve.c \
	./operator/operator_swap.c ./operator/operator_rrr.c  \
	./operator/operator_rotate.c ./operator/operator_push.c \
	move.c main.c

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
