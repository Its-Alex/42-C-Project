/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:47:17 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/15 17:33:26 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <attr/xattr.h>
# include <sys/stat.h> 

# ifndef WIN32
    #include <sys/types.h>
# endif

typedef struct dirent	t_dir;
typedef struct stat 	t_stat;
typedef struct passwd 	t_pwd;
typedef struct group 	t_grp;

int		read_dir(char *path);
int		open_dir(char *path, int sneaky);
void	print_access(t_stat *elem);

#endif