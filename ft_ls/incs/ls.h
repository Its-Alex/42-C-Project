/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:47:17 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/14 12:33:26 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <attr/xattr.h>
# include <sys/stat.h> 
# include <unistd.h>

# ifndef WIN32
    #include <sys/types.h>
# endif

typedef struct dirent	t_dir;
typedef struct stat 	t_stat;

int		read_dir(char *path);

#endif