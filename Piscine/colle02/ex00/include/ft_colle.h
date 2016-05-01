/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 14:10:18 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 21:30:54 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLLE_H
# define FT_COLLE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

typedef struct	s_dimension
{
	int			x;
	int			y;
}				t_dimension;
typedef struct	s_verif
{
	int pipe;
	int find;
}				t_verif;

void			ft_putnbr(int nb);
void			ft_putchar(char c);
int				ft_atoi(char *str);
void			ft_putstr(char *src);
void			colle00(char *tab, int x, int y);
void			colle01(char *tab, int x, int y);
void			colle02(char *tab, int x, int y);
void			colle03(char *tab, int x, int y);
void			colle04(char *tab, int x, int y);
int				ft_strcmp(char *s1, char *s2);

#endif
