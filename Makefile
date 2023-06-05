# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: m_kamal <m_kamal@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/01 07:57:57 by m_kamal           #+#    #+#              #
#    Updated: 2023/06/05 13:23:21 by m_kamal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap

SRCS =	./sources/main.c\
		./sources/utils.c\
		./sources/utils2.c\
		./sources/input.c\
		./sources/input_utils.c\
		./sources/init.c\
		./sources/errors.c\
		./sources/parse.c\
		./sources/swap.c\
		./sources/rotate.c\
		./sources/rev_rotate.c\
		./sources/push.c\

OFILES = $(SRCS:.c=.o)

CC = gcc -g

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

RM = rm -f

all : $(NAME)

$(NAME):	ANNOUNCE $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

ANNOUNCE:
	@echo "\033[0;33mCompiling PushSwap..."

clean:
	@echo "\033[31mRemoving .o files"
	@$(RM) $(OFILES)

fclean: clean
	@echo "\033[31mRemoving PushSwap"
	@$(RM) $(NAME)

re: fclean all

.SILENT: $(NAME) $(OFILES)

.PHONY: all clean fclean re

#valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./pushswap 1 2 3
