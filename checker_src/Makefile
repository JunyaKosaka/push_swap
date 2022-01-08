# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/09 00:07:47 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../checker

HEADERFILE = ../includes/checker.h

SRCS = main.c \
	checker.c \
	get_next_line.c \
	get_next_line_utils.c

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
	${RM} -f $(OBJS)

fclean : clean
	make fclean -C ../libft
	make fclean -C ../utils
	${RM} -f $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus