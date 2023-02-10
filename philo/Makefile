# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-kame <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:49:59 by hel-kame          #+#    #+#              #
#    Updated: 2023/02/10 19:55:04 by hel-kame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_DIR = src

BIN_DIR = bin/

SRC =	$(SRC_DIR)/main.c		\
		$(SRC_DIR)/utils.c		\


OBJ = $(SRC:$(SRC_DIR)/%.c=$(BIN_DIR)%.o)

INCLUDES = ./includes

CFLAGS = -I$(INCLUDES)

all :	$(NAME)

bonus :	$(NAME_BONUS)

$(BIN_DIR)%.o : $(SRC_DIR)/%.c
		@ $(CC) -I$(INCLUDES) -c $< -o $@

$(NAME) :	$(BIN_DIR) $(OBJ)
			@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
			@ echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mDone ! ✅"

$(BIN_DIR) :
		@ mkdir -p $(BIN_DIR)

clean :
		@ rm -f $(OBJ)
		@ rm -rf $(BIN_DIR)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove binary files .. 🧹"

fclean : clean
		@ rm -f $(NAME)
		@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRemove executable .. 🗑️"

re :
	@echo "\e[33m\e[1m\tMake\e[0m [🗿] : \e[1mRecompile .. 🔄"
	@ $(MAKE) -s fclean all

.PHONY: all clean fclean re
