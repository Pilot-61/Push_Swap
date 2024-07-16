# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 23:47:56 by mes-salh          #+#    #+#              #
#    Updated: 2024/07/16 04:02:46 by mes-salh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = Mandatory/push_swap.c Mandatory/parsing.c Mandatory/Tools/split.c Mandatory/Tools/helpers2.c Mandatory/Tools/ft_strjoin.c Mandatory/Tools/ft_atoi.c Mandatory/push.c  \
		Mandatory/swap.c Mandatory/rotate.c Mandatory/rev_rotate.c Mandatory/Tools/helpers.c Mandatory/Tools/helpers1.c Mandatory/sort_x.c Mandatory/Tools/indexing.c \
		Mandatory/sort_plus.c
OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror 

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

Mandatory/%.o: Mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

m: all clean

.PHONY: all clean fclean re
