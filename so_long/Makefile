# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: touahman <touahman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 17:41:23 by touahman          #+#    #+#              #
#    Updated: 2024/02/03 12:27:25 by touahman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCF = $(addprefix src/, main.c list_utils.c list_utils2.c parse_map.c parse_map2.c parse_map3.c parse_map4.c render.c handler.c moves.c)

GNL_SRCF = $(addprefix gnl/, get_next_line.c get_next_line_utils.c)
PRINTF_SRCF = $(addprefix printf/, ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_put_hex.c ft_put_bighex.c ft_putnbr_u.c ft_print_add.c)
OBJF = $(SRCF:.c=.o)
GNL_OBJF = $(GNL_SRCF:.c=.o)
PRINTF_OBJF = $(PRINTF_SRCF:.c=.o)

NAME = so_long

all : $(NAME)

$(NAME): $(OBJF) $(GNL_OBJF) $(PRINTF_OBJF)
	$(CC) $(CFLAGS) $^  -lmlx -framework OpenGL -framework AppKit -o $@

%.o : %.c ./src/header.h ./printf/ft_printf.h ./gnl/get_next_line.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJF) $(GNL_OBJF) $(PRINTF_OBJF)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
