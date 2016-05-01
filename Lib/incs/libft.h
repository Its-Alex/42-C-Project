/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:48:39 by alex              #+#    #+#             */
/*   Updated: 2016/05/01 20:57:31 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

char    *ft_itoa(int value, char *str, int base);
void    ft_fprintf(int output, const char *str, ...);
int     ft_atoi(char *str);

int     ft_putchar(char c, int output);
void    ft_putnbr(int nb, int output);
void    ft_putstr(char *str, int output);

int     ft_strcmp(char *s1, char *s2);
int     ft_strlen(char *str);
char    *ft_strdup(char *src);
char    *ft_strrev(char *str);

void    ft_swap(int *a, int *b);

void    *ft_memset(void *s, int c, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memccpy (void *dest, const void *src, int c, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    ft_bzero(void *s, size_t n);

#endif
