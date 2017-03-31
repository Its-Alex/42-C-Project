/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 09:25:42 by malexand          #+#    #+#             */
/*   Updated: 2015/07/23 11:35:24 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_display_file.h"

int		ft_putcontents(char **argv)

{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Erreur open()\n", 14);
		return (-1);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		write(2, "Erreur close()\n", 15);
		return (-1);
	}
	ft_putstr(buf);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_putcontents(argv) == 1)
			return (1);
		else
			return (0);
	}
	else if (argc > 1)
		write(2, "Too many arguments.\n", 20);
	else if (argc == 1)
		write(2, "File name missing.\n", 19);
	return (1);
}
