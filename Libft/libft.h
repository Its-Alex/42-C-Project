/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 18:36:27 by alex              #+#    #+#             */
/*   Updated: 2016/05/08 10:19:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_
#define _LIBFT_

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);

void    ft_putchar(char c);
void    ft_putnbr(int nb);
void    ft_putstr(char const *str);
void    ft_fprintf(char const *str, ...);

size_t  ft_strlen(char const *str);
int     ft_strcmp(char *s1, char *s2);
int     ft_strequ(char const *s1, char const *s2);
int     ft_strnequ(char const *s1, char const *s2, size_t n);
char    *ft_strcpy (char *dest, char const *src);
char    *ft_strncpy (char *dest, char const *src, size_t n);
char    *ft_strnew(size_t size);
char    *ft_strdup(char *src);
char    *ft_strrev(char *str);
char    *ft_strmap(char const *s, char (*f)(char));
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char    *ft_strsub(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_strtrim(char const *s);
char    **ft_strsplit(char const *s, char c);
void    ft_strdel(char **as);
void    ft_strclr(char *s);
void    ft_striter(char *s, void (*f)(char *));
void    ft_striteri(char *s, void (*f)(unsigned int, char *));


int     ft_atoi(char *str);
char    *ft_itoa(int value, char *str, int base);
void    ft_swap(int *a, int *b);

int     ft_memcmp(const void *s1, const void *s2, size_t n);
void    ft_bzero(void *s, size_t n);
void    ft_memdel(void **ap);
void    *ft_memset(void *s, int c, size_t n);
void    *ft_memcpy(void *dest, const void *src, size_t n);
void    *ft_memccpy (void *dest, const void *src, int c, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memchr(const void *s, int c, size_t n);
void    *ft_memalloc(size_t size);

#endif
