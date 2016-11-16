/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:27:39 by malexand          #+#    #+#             */
/*   Updated: 2016/11/15 11:02:47 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define BUF_SIZE 4096

int			ft_check_tetriminos(const char *str);
int			resolve(char **tab, char **tryresult, int *pattern, int x);
int			ft_isupper(char c);
int			resolve_son(char **tab, char **tryresult, int *pattern, int x);
int			check_valid_point(char *tab, char **tryresult, int i, int j);
int			check_nbsynb(char *str, int index, int *nb_sym, int *check);

char		**holy_result(int x);
char		*ft_form_tetri(char *str);
char		*ft_create_str(const char *name_file);
char		*ft_strjoin_free(char *s1, const char *s2);
char		*ft_strsub(const char *s, unsigned int start, size_t len);

size_t		ft_strlen(const char *str);

void		holy_resolve(char **tab, int pat);
void		ft_putchar(char c);
void		ft_free_array(char **str);
void		putabl(char **tabl);
void		ft_putstr(const char *str);

#endif
