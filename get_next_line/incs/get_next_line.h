/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:49:30 by malexand          #+#    #+#             */
/*   Updated: 2016/11/18 17:26:36 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# include <unistd.h>
# include <ctype.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <regex.h>

int get_next_line(const int fd, char **line);

#endif
