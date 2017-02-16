/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:49:30 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 11:16:44 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024
# define SIZE_FD 2147483647
# include "../libft/incs/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <regex.h>

int get_next_line(const int fd, char **line);

#endif
