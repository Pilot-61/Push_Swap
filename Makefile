# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mes-salh <mes-salh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/11 23:47:56 by mes-salh          #+#    #+#              #
#    Updated: 2024/07/17 01:21:08 by mes-salh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker

SRCM = Mandatory/push_swap.c Mandatory/parsing.c Mandatory/Tools/split.c \
	Mandatory/Tools/helpers2.c Mandatory/Tools/ft_strjoin.c \
	Mandatory/Tools/ft_atoi.c Mandatory/push.c Mandatory/swap.c \
	Mandatory/rotate.c Mandatory/rev_rotate.c Mandatory/Tools/helpers.c \
	Mandatory/Tools/helpers1.c Mandatory/sort_x.c \
	Mandatory/Tools/indexing.c Mandatory/sort_plus.c

SRCB = Bonus/Get_Next_Line/get_next_line.c \
	Bonus/Get_Next_Line/get_next_line_utils.c Bonus/checker.c \
	Bonus/push.c Bonus/swap.c \
	Bonus/rotate.c Bonus/rev_rotate.c Bonus/Tools/helpers.c \
	Bonus/Tools/helpers2.c Bonus/Tools/ft_strjoin.c \
	Bonus/parsing.c Bonus/Tools/split.c Bonus/Tools/ft_atoi.c  Bonus/Tools/helpersv2.c

OBJM = $(SRCM:.c=.o)
OBJB = $(SRCB:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g

HEADER = push_swap.h
HEADERB = push_swap_bonus.h

all: $(NAME)
bonus : $(NAMEB)

$(NAME): $(OBJM)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJM)

$(NAMEB): $(OBJB)
	$(CC) $(CFLAGS) -o $(NAMEB) $(OBJB)

Mandatory/%.o: Mandatory/%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c $(HEADERB)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJM) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAMEB)

re: fclean all

.PHONY: all clean fclean re
