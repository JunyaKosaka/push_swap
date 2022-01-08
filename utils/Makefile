# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/09 01:51:50 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutil.a

HEADERFILE = ../includes/utils.h

SRCS = operator_push.c \
	operator_rotate.c \
	operator_rrr.c \
	operator_swap.c \
	init_stack.c \
	bubble_sort.c \
	error_handler.c \
	free.c \
	show.c \
	utils.c \
	utils2.c \
	utils3.c \
	dlst_status.c \
	dlst_function.c \
	compress_ans.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	make $(FLAGS) -C ../libft
	cp ../libft/libft.a $(NAME)
	ar rc $@ $^

all	: $(NAME)

%.o : %.c $(HEADERFILE)
	gcc $(FLAGS) -c $< -o $@

bonus : all

clean :
	make clean -C ../libft
	${RM} -f $(OBJS) $(BNS_OBJS)

fclean : clean
	make fclean -C ../libft
	${RM} -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus