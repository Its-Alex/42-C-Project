/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/16 02:04:44 by alex              #+#    #+#             */
/*   Updated: 2016/03/20 14:07:52 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/tool.h"

static int      openfile(int *fd, const char *path)
{
	if ((*fd = open(path, O_RDWR, 0777)) == -1)
	{
		perror("Error open ");
		return (-1);
	}
	return (0);
}

static int      closefile(int *fd)
{
	if ((close(*fd)) < 0)
	{
		perror("Error close ");
		return (-1);
	}
	return (0);
}

int             readfile(char *buffer, char *path)
{
	int  count;
	int *fd;

	fd = malloc(sizeof(int));
	if (openfile(fd, path) == -1)
		return (-1);
	if ((count = read(*fd, buffer, BUFFER_SIZE)) < 0)
	{
		perror("Error read ");
		return (-1);
	}
	buffer[count] = '\0';
	if ((closefile(fd)) == -1)
		return (-1);
	free(fd);
	return (0);
}
