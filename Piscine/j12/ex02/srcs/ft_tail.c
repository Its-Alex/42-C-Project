/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 22:27:50 by malexand          #+#    #+#             */
/*   Updated: 2015/07/24 23:34:15 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_tail.h"

int		ft_tail_nobuf(char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUFFER_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Erreur open()");
		return (-1);
	}
	while ((ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		buf[ret] = '\0';
		ft_putstr(buf);
	}
	if (close(fd) == -1)
	{
		ft_putstr("Erreur close()");
		return (-1);
	}
	return (1);
}

int		ft_tail_buf(char **argv)
{
	int		fd;
	int		ret;
	char	buf[ft_atoi(argv[2]) + 1];

	fd = open(argv[3], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Erreur open()");
		return (-1);
	}
	ret = read(fd, buf, ft_atoi(argv[2]));
	buf[ret] = '\0';
	ft_putstr(buf);
	if (close(fd) == -1)
	{
		ft_putstr("Erreur close()");
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_tail_nobuf(argv) == 1)
			return (1);
		else
			return (0);
	}
	else if (argc == 4)
	{
		if (argv[1][0] == '-' && argv[1][1] == 'c')
		{
			if (ft_tail_buf(argv) != 1)
				return (0);
			else
				return (1);
		}
		else
			ft_putstr("Tail: illegal option\n");
	}
	else if (argc > 4 || argc == 3)
		write(2, "Too many arguments.\n", 20);
	else if (argc == 1)
		write(2, "File name missing.\n", 19);
	return (1);
}
