/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/17 11:52:19 by alex              #+#    #+#             */
/*   Updated: 2016/04/03 18:30:19 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOL_H
# define TOOL_H
# define BUFFER_SIZE 4096
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

void    perror(const char *chaine);
int     readfile(char *buffer, char *path);
int     cleartab(char *tab);
void    check_column(char *tab, char *nb_file);
void    check_tab(char *tab, char *nb_file);
void    check_array(char *tab, char *nb_file);
void    flx_fprintf(int output, const char *str, ...);
int     ft_atoi(char *str);
void    check_endline(char *tab, char *nb_file);

#endif
