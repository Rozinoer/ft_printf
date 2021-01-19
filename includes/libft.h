/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmyesha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:47:49 by dmyesha           #+#    #+#             */
/*   Updated: 2021/01/19 19:45:31 by dmyesha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *src);
char				*ft_strcpy(char *dest, char *src);
int					ft_atoi(const char *str);
char				*ft_itoa(long int n);
int					ft_toupper(int c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
int					ft_putchar(char c);
int					ft_rank(unsigned long long num, unsigned long long base);
int					ft_putstr(char *s);

#endif
