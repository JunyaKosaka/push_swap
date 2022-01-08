# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/09 00:15:13 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
PUSH_SWAP_DIR = ./ps_src
CHECKER_DIR = ./checker_src

$(NAME) : #./ps_src/*.c
	make -C $(PUSH_SWAP_DIR)
# cp $(PUSH_SWAP_DIR)/$(NAME) ./

$(CHECKER) :
	make -C $(CHECKER_DIR)
# cp $(CHECKER_DIR)/$(CHECKER) ./

all : $(NAME) $(CHECKER)

bonus : $(CHECKER)

clean :
	make clean -C $(PUSH_SWAP_DIR)
	make clean -C $(CHECKER_DIR)

fclean :
	make fclean -C $(PUSH_SWAP_DIR)
	rm -f $(NAME)
	make fclean -C $(CHECKER_DIR)
	rm -f $(CHECKER)

re : fclean all

.PHONY: all clean fclean re bonus