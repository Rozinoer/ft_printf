# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/15 17:49:36 by dmyesha           #+#    #+#              #
#    Updated: 2020/11/15 17:49:42 by dmyesha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS=-c -Wall -Wextra -Werror
CC=gcc
HEADER=libft.h
SOURCES= ft_strcpy.c ft_putchar.c  ft_rank.c ft_putstr.c ft_memcpy.c ft_strlen.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isalnum.c ft_toupper.c ft_atoi.c ft_strdup.c ft_strjoin.c ft_itoa.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SOURCES:c=o}

BOBJS = ${BONUS:c=o}

NAME=libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar r libft.a $(OBJS)
	

bonus: ${OBJS} ${BOBJS}
	ar r libft.a ${OBJS} ${BOBJS}


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $< 
	
clean:
	rm -rf *.o

fclean: clean
	rm -f $(NAME)


re: fclean all

