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

NAME = libftprintf.a

TEST = ft_printf

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_L = srcs/

INCLUDES = -I includes/ -I libft/

LIST = 		ft_printf.c \
			ft_print_c.c \
			ft_print_s.c \
			ft_print_d.c \
			ft_print_x.c \
			ft_print_u.c \
			ft_print_p.c \
			ft_parce.c \
			ft_seek.c \


OBJS =$(SRCS:.c=.o)

SRCS = $(addprefix $(DIR_L), $(LIST))

all: $(NAME)

$(NAME): my_lib $(OBJS)
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

my_lib:
	make -C $(LIBFT)

%.o: %.c includes/ft_printf.h
	gcc -g $(FLAGS) $(INCLUDES) -c $< -o $@

test: $(NAME)
	gcc -g $(INCLUDES) srcs/main.c -lftprintf -L. -o $(TEST)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

tclean:
	rm $(TEST)

re: fclean all

.PHONY: fclean re norme all clean