# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:46:04 by ffidha            #+#    #+#              #
#    Updated: 2023/12/11 15:05:15 by ffidha           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libftprintf.a

SRC =   ft_printf.c \
ft_printhex.c \
ft_printchar.c \
ft_printstr.c \
ft_printuint.c \
ft_putdecimal.c \
ft_printptr.c \

OBJ = $(SRC:.c=.o)
CC = cc

CFLAGS = -Wall -Werror -Wextra

DEL = rm -rf

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
 
clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
