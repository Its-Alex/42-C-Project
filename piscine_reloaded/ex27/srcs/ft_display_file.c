/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:25:15 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 17:19:11 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_display_file.h"

void	ft_putchar(int out, const char c)
{
	write(out, &c, 1);
}

void	ft_putstr(int out, const char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar(out, str[count]);
		count++;
	}
}

int		ft_read_file(int fd)
{
	int		ret;
	char	buf[BUF_SIZE + 1];

	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		if (ret < 0)
			return (-1);
		else
		{
			buf[BUF_SIZE] = '\0';
			ft_putstr(1, (const char *)buf);
		}
	}
	return (1);
}

int		ft_display_file(const char *file_name)
{
	int		fd;

	if ((fd = open(file_name, O_RDONLY)) > 0)
	{
		if (ft_read_file(fd) < 0)
		{
			return (-1);
		}
		if (close(fd) < 0)
		{
			return (-1);
		}
	}
	else
		return (-1);
	return (1);
}

int		main(int argc, char const **argv)
{
	int		count;

	count = 1;
	if (argc <= 1)
		ft_putstr(2, "File name missing.\n");
	else if (argc > 2)
		ft_putstr(2, "Too many arguments.\n");
	else
		ft_display_file(argv[1]);
	return (0);
}
