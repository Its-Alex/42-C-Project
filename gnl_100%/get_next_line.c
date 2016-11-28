/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 11:17:25 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/28 16:23:03 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add(char *s1, char *s2)
{
	char		*cool;
	int			i;
	int			j;
	int			len;
	char		*leaks_1;

	leaks_1 = s1;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	cool = (char *)malloc(sizeof(char) * (len + 1));
	while (s1[j])
		cool[i++] = s1[j++];
	j = 0;
	while (s2[j])
		cool[i++] = s2[j++];
	cool[i] = '\0';
	free(leaks_1);
	return (cool);
}

char	*get_my_line(char *str, char **line)
{
	char	*stock_2;
	int		i;
	int		j;

	j = 0;
	i = 0;
	*line = ft_strdup(str);
	stock_2 = ft_strdup(str);
	while (str[i])
	{
		if (str[i] == '\n' || str[i + 1] == '\0')
		{
			if (str[i] != '\n' && str[i + 1] == '\0')
				line[0][j++] = str[i];
			line[0][j] = '\0';
			j = 0;
			i++;
			while (str[i])
				stock_2[j++] = str[i++];
			stock_2[j] = '\0';
			return (stock_2);
		}
		line[0][j++] = str[i++];
	}
	return (stock_2);
}

char	*ft_leaks_malloc(char **line, char *stock_1[FD_SIZE], int fd)
{
	char	*leaks;

	leaks = stock_1[fd];
	stock_1[fd] = get_my_line(stock_1[fd], line);
	free(leaks);
	return (stock_1[fd]);
}

int		get_next_line(const int fd, char **line)
{
	static char		*stock[FD_SIZE];
	long int		ret;
	char			*tmp;

	if (BUFF_SIZE < 1 || fd < 0 || line == NULL || fd > FD_SIZE)
		return (-1);
	while ((ft_check_new_line(stock[fd])) != 1)
	{
		if (!(tmp = (char *)malloc(BUFF_SIZE + 1)))
			return (-1);
		if ((ret = read(fd, tmp, BUFF_SIZE)) == -1)
			return (-1);
		tmp[ret] = '\0';
		stock[fd] = ft_add(stock[fd], tmp);
		free(tmp);
		if (ret == 0 && (*stock[fd] == '\0' || !stock[fd]))
		{
			*line = NULL;
			return (0);
		}
		else if (ret == 0)
			break ;
	}
	stock[fd] = ft_leaks_malloc(line, stock, fd);
	return (1);
}
