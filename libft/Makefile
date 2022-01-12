# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:59:25 by souchen           #+#    #+#              #
#    Updated: 2022/01/08 21:42:19 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
CC=GCC
FLAGS    = -Wall -Werror -Wextra
AR=ar crs
RM=rm -rf
HEADER = libft.h
FICHIER= ft_strlen ft_atoi ft_bzero ft_putchar_fd ft_putstr_fd ft_putnbr_fd  
OBJ= $(FICHIER:=.o)
NAME=libft.a

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@
	

clean:
	$(RM) $(OBJ) 

fclean: clean
	$(RM) $(NAME)
re: fclean all
