/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 11:22:15 by malexand          #+#    #+#             */
/*   Updated: 2015/07/24 22:38:51 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_cat.h"

int		ft_putcontents(char **argv)

{
	int		fd;
	int		ret;
	char	buffer[BUFFER_SIZE + 1];

	ret = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Erreur open()\n", 14);
		return (-1);
	}
	while ((ret = read(fd, buffer, BUFFER_SIZE)) != 0)
	{
		buffer[ret] = '\0';
		ft_putstr(buffer);
	}
	if (close(fd) == -1)
	{
		write(2, "Erreur close()\n", 15);
		return (-1);
	}
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
