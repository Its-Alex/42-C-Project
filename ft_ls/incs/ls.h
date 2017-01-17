/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 21:47:17 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/17 13:38:22 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

# include "../libft/incs/libft.h"
# include <stdio.h>
# include <time.h>
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/stat.h>

# ifndef WIN32
#  include <sys/types.h>
# endif

typedef struct dirent	t_dir;
typedef struct stat		t_stat;
typedef struct passwd	t_pwd;
typedef struct group	t_grp;

int			core(char *flags, char **path);
void		print_access(t_stat *elem);
t_list		*open_dir(char *path, int sneaky);

#endif
