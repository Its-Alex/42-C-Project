/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:27:39 by malexand          #+#    #+#             */
/*   Updated: 2016/11/10 15:27:42 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# define BUF_SIZE 2

int			ft_check_tetriminos(const char *str);
void		ft_free_array(char **str);
char		**ft_split_tetri(const char *name_file);
char		*ft_form_tetri(char *str);

#endif
