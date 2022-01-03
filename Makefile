# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkosaka <jkosaka@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 18:34:44 by jkosaka           #+#    #+#              #
#    Updated: 2022/01/03 11:20:34 by jkosaka          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
# CHECKER = checker
PUSH_SWAP_DIR = ./ps_src
# CHECKER_DIR = ./checker_src

all:
	make -C $(PUSH_SWAP_DIR)
	cp $(PUSH_SWAP_DIR)/$(PUSH_SWAP) ./
# make -C $(CHECKER_DIR)
# cp $(CHECKER_DIR)/$(CHECKER) ./

clean:
	make -C $(PUSH_SWAP_DIR) clean;
# make -C $(CHECKER_DIR) clean;

fclean:
	make -C $(PUSH_SWAP_DIR) fclean;
	rm -f $(PUSH_SWAP)
# make -C $(CHECKER_DIR) fclean;
# rm -f $(CHECKER)

re: fclean all

bonus : all

.PHONY: all clean fclean re bonus