# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2021/12/26 11:29:19 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERFILE = ft_printf.h

SRCS = ft_parse_spec.c ft_print_c.c ft_print_d.c ft_print_lx.c \
	ft_print_p.c ft_print_s.c ft_print_u.c ft_print_x.c ft_printf.c\
	ft_print_percent.c ./utils/ft_get_digits.c ./utils/ft_putchr.c

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
	${RM} -rf $(OBJS) $(BNS_OBJS)

fclean : clean
	make fclean -C ../libft
	${RM} -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
