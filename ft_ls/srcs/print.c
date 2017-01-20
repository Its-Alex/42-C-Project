/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 17:28:29 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/20 21:46:03 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ls.h"

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

void		print_dir(char *flags, char *name)
{
	t_stat		file_stat;
	t_pwd		*pwd;
	t_grp		*grp;

	stat(name, &file_stat);
	grp = getgrgid(file_stat.st_gid);
	pwd = getpwuid(file_stat.st_uid);

	if (ft_strchr(flags, 'l') != NULL)
	{
		print_access(file_stat);
		ft_putstr("  ");
		ft_putlong(file_stat.st_nlink);
		ft_putstr("  ");
		ft_putstr(pwd->pw_name);
		ft_putstr("  ");
		ft_putstr(grp->gr_name);
		ft_putstr("  ");
		print_size(file_stat.st_size);
		ft_putstr("  ");
		ft_putlong(file_stat.st_atime);
		ft_putstr("  ");
	}
	ft_putstr(name);
	ft_putendl("");
}
