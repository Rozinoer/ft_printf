cmake_minimum_required(VERSION 3.17)
project(ft_printf C)

set(CMAKE_C_STANDARD 99)

add_executable(ft_printf main.c
        ft_print_/ft_parce.c
        ft_print_/ft_print_c.c
        ft_print_/ft_print_d.c
        ft_print_/ft_print_p.c
        ft_print_/ft_print_s.c
        ft_print_/ft_print_u.c
        ft_print_/ft_print_x.c
        ft_print_/ft_seek.c
        ft_print_/ft_printf.c
        includes/libft.h
        includes/printflib.h
        libft/ft_atoi.c
        libft/ft_rank.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_isascii.c
        libft/ft_isdigit.c
        libft/ft_itoa.c
        libft/ft_toupper.c
        libft/ft_strjoin.c
        libft/ft_strdup.c
        libft/ft_strcpy.c
        libft/ft_putchar.c
        libft/ft_putstr.c
        libft/ft_strlen.c libft/ft_memcpy.c)