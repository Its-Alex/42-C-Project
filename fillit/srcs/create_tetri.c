/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:39:13 by malexand          #+#    #+#             */
/*   Updated: 2016/11/21 18:16:01 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fillit.h"
#include <stdio.h>

void			ft_free_array(char **tab)
{
	while (*tab)
	{
		free(*tab);
		*tab = NULL;
	}
	free(tab);
	tab = NULL;
}

static	char	*ft_readfile(int fd)
{
	int		ret;
	int		count_read;
	char	buf[BUF_SIZE + 1];
	char	*str;

	count_read = 0;
	if ((str = (char *)malloc(sizeof(*str) * 1)) == NULL)
		return (NULL);
	str[0] = '\0';
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		str = ft_strjoin_free(str, buf);
		count_read += ret;
		str[count_read] = '\0';
		if (count_read > 21 * 26 + 1)
			ret = -1;
	}
	if (ret == -1 || !str[0])
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	return (str);
}

char			*ft_create_str(const char *name_file)
{
	int		fd;
	char	*str;

	if ((fd = open(name_file, O_RDONLY)) < 0)
		return (NULL);
	str = ft_readfile(fd);
	if (close(fd) == -1 || str == NULL)
	{
		if (str != NULL)
			free(str);
		ft_putstr("error\n");
		return (NULL);
	}
	return (str);
}
