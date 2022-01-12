# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: souchen <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/08 20:34:13 by souchen           #+#    #+#              #
#    Updated: 2022/01/12 16:05:46 by souchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
CSRC = client.c
CSRCB = client-bonus.c
CSRC_OBJ = $(CSRC:.c=.o)
CSRCB_OBJ =  $(CSRCB:.c=.o)
SSRC = server.c
SSRCB = server-bonus.c
SSER_OBJ = $(SSRC:.c=.o)
SSERB_OBJ = $(SSRCB:.c=.o)

LIBFT = libft/libft.a

LIBFT_DIR = libft/

HEADER = Minitalk.h

NAME = client

NAME1 = server

NAMEB = clientB
NAME1B = serverB

all: $(NAME) $(NAME1) $(NAMEB) $(NAME1B)

$(NAME): $(CSRC_OBJ) $(LIBFT) 
	$(CC) $(CSRC_OBJ) $(LIBFT) -o $(NAME)

$(NAME1): $(SSER_OBJ) $(LIBFT)
	$(CC) $(SSER_OBJ) $(LIBFT) -o $(NAME1)

$(NAMEB): $(CSRCB_OBJ) $(LIBFT)
	$(CC) $(CSRCB_OBJ) $(LIBFT) -o $(NAMEB)

$(NAME1B): $(SSERB_OBJ) $(LIBFT)
	$(CC) $(SSERB_OBJ) $(LIBFT) -o $(NAME1B)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CSRC_OBJ) $(SSER_OBJ)
	$(RM) $(CSRCB_OBJ) $(SSERB_OBJ) 

fclean: clean
	$(RM) $(NAME) $(NAME1)
	$(RM) $(NAMEB) $(NAME1B)
re : fclean all 
