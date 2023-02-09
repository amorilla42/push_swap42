# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amorilla <amorilla@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/18 18:41:38 by jdomingu          #+#    #+#              #
#    Updated: 2023/02/09 21:06:12 by amorilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	push_swap

SRCS = 	src/ft_push_swap.c \
		src/ft_fill_stacks.c \
		src/ft_movements.c \
		src/ft_movements_reverse.c \
		src/ft_parse_input.c \
		src/ft_utilities.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:			$(NAME)

$(NAME):		$(LIBFT_LIB)
				$(CC) $(CFLAGS) $(SRCS) $(LIBFT_LIB) -o $(NAME)

$(LIBFT_LIB):	
				@make bonus -C $(LIBFT)

clean:
				$(RM) $(OBJS)
				@make clean -C $(LIBFT)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(LIBFT_LIB)

re:			fclean all

.PHONY:			all clean fclean re
