# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/12/26 00:31:09 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADERFILE = push_swap.h

SRCS = push_swap.c push_swap_utils.c push_swap_utils_dlist.c \
	solve.c operator.c move.c main.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ./libft
	cp libft/libft.a $(NAME)
	ar rc $@ $^

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

test : 
	gcc ${FLAGS} $(SRCS) ./libft/libft.a -o push_swap

.PHONY : all clean fclean re bonus
