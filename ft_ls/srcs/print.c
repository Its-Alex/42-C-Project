/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:28:29 by skyzie            #+#    #+#             */
/*   Updated: 2017/02/28 22:52:02 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

char			*get_filename(char *path)
{
	int		count;
	char	**tab;
	char	*filename;

	if (ft_strchr(path, '/') == 0)
		return (path);
	count = 0;
	tab = ft_strsplit(path, '/');
	while (tab[count])
		count++;
	filename = ft_strnew(ft_strlen(tab[count - 1]) - 1);
	filename = ft_strcpy(filename, tab[count - 1]);
	ft_freetab(tab);
	return (filename);
}

static void	print_access(t_stat elem)
{
	ft_putchar((S_ISFIFO(elem.st_mode)) ? 'p' : '\0');
	ft_putchar((S_ISCHR(elem.st_mode)) ? 'c' : '\0');
	ft_putchar((S_ISDIR(elem.st_mode)) ? 'd' : '\0');
	ft_putchar((S_ISBLK(elem.st_mode)) ? 'b' : '\0');
	ft_putchar((S_ISREG(elem.st_mode)) ? '-' : '\0');
	ft_putchar((S_ISLNK(elem.st_mode)) ? 'l' : '\0');
	ft_putchar((S_ISSOCK(elem.st_mode)) ? 's' : '\0');
	ft_putchar((elem.st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((elem.st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((elem.st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((elem.st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((elem.st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((elem.st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((elem.st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((elem.st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((elem.st_mode & S_IXOTH) ? 'x' : '-');
}

static void	print_size(long elem)
{
	ft_putlong(elem);
}

void		print(char *flags, char *name, int path)
{
	t_stat		file_stat;
	t_pwd		*pwd;
	t_grp		*grp;
	char		*filename;

	stat(name, &file_stat);
	grp = getgrgid(file_stat.st_gid);
	pwd = getpwuid(file_stat.st_uid);
	if (path == 0)
		filename = get_filename(name);
	else
		filename = name;
	if (ft_strchr(flags, 'l') != NULL)
	{
		print_access(file_stat);
		ft_putstr(" ");
		ft_putlong(file_stat.st_nlink);
		ft_putstr(" ");
		ft_putstr(pwd->pw_name);
		ft_putstr(" ");
		ft_putstr(grp->gr_name);
		ft_putstr(" ");
		print_size(file_stat.st_size);
		ft_putstr(" ");
		ft_putlong(file_stat.st_atime);
		ft_putstr(" ");
		ft_putendl(filename);	
	}
	else
		ft_putendl(filename);
	//ft_strdel(&filename);
}
