# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmalka <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 12:15:11 by gmalka            #+#    #+#              #
#    Updated: 2021/12/09 14:51:00 by gmalka           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

NAME_B		=	checker

SRC			=	add_and_sort.c	bring_last.c	fill_delete_fract.c\
				ft_split.c		ft_strlen.c		ft_substr.c\
				match_numbers.c	operations.c	operations_2.c\
				push_swap.c		swap.c			utils2.c\
				utils.c

SRC_B		=	operations.c		operations_2.c		checker_bonus.c\
				fill_delete_fract.c	ft_split.c			ft_strlen.c\
				ft_substr.c			gnl/get_next_line.c	gnl/get_next_line_utils.c
HEADER		=	push_swap.h

HEADER_B	=	push_swap_bonus.h

OBJ			=	$(SRC:.c=.o)

OBJB		=	$(SRC_B:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

bonus		:	$(NAME_B)

$(NAME)		:	$(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_B)	:	$(OBJB) $(HEADER_B)
	$(CC) $(CFLAGS) $(OBJB) -o $(NAME_B)

clean		:
	$(RM) $(OBJ) $(OBJB)

fclean		:	clean
	$(RM) $(NAME) $(NAME_B)

re			:	fclean all bonus
