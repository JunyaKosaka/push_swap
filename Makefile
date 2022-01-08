# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/09 01:15:04 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
PUSH_SWAP_DIR = ./ps_src
CHECKER_DIR = ./checker_src

$(NAME) : empty
	make -C $(PUSH_SWAP_DIR)

$(CHECKER) : empty
	make -C $(CHECKER_DIR)

all : $(NAME) $(CHECKER)

bonus : $(CHECKER)

clean :
	make clean -C $(PUSH_SWAP_DIR)
	make clean -C $(CHECKER_DIR)

fclean : clean
	rm -f $(NAME)
	rm -f $(CHECKER)

re : fclean all

empty : 

.PHONY: all clean fclean re bonus empty