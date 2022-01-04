# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/04 17:56:44 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker
PUSH_SWAP_DIR = ./ps_src
CHECKER_DIR = ./checker_src

$(NAME) :
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(NAME) ./

$(CHECKER) :
	make -C $(CHECKER_DIR)
	cp $(CHECKER_DIR)/$(CHECKER) ./

all : $(NAME) $(CHECKER)

bonus : $(CHECKER)

clean :
	make -C $(PUSH_SWAP_DIR) clean;
	make -C $(CHECKER_DIR) clean;

fclean :
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(NAME)
	make -C $(CHECKER_DIR) fclean;
	rm -f $(CHECKER)

re : fclean all

.PHONY: all clean fclean re bonus