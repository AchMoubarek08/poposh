# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/12 02:06:19 by amoubare          #+#    #+#              #
#    Updated: 2022/04/12 02:07:57 by amoubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all bonus clean fclean re

NAME = push_swap
NAME_BONUS = checker

SRC = instructions.c Push_swap.c BigSort.c BigSortt.c \
		utils.c error.c MiniSort.c utils2.c utils3.c shortcut.c \

SRC_BONUS =	instructions.c BigSort.c BigSortt.c \
			  utils.c error.c MiniSort.c utils2.c utils3.c shortcut.c \
			  get_next_line.c get_next_line_utils.c checker.c
OBJECT = $(SRC:.c=.o)
OBJECT_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror $(SRC) -o $(NAME)
	@echo "✅✅✅"

bonus:
	@gcc -Wall -Wextra -Werror $(SRC_BONUS) -o $(NAME_BONUS)
	@echo "🎁🎁🎁"

clean:
	@rm -f $(OBJECT) $(OBJECT_BONUS)
	@echo "🗑️ 🗑️ 🗑️"
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "🚮🚮🚮"
re: fclean all