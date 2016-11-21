/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:49:20 by malexand          #+#    #+#             */
/*   Updated: 2016/11/21 16:13:41 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

static	char		*freestrjoin(char *s1, char *s2)
{
	char	*tmp;

	tmp = s1;
	if (!(s1 = ft_strjoin(tmp, s2)))
		return (NULL);
	free(tmp);
	return (s1);
}

static	char		*read_file(const int fd, char *str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];

	ret = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = freestrjoin(str, buf);
		if (ft_strchr(str, '\n'))
		 	break ;
	}
	if (ret == -1)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}

static	int			fill_save_line(char *save, char **line)
{
	int		count;
	char	*tmp;

	count = 0;
	while (save[count] != '\n' && save[count] != '\0')
		count++;
	*line = ft_strsub(save, 0, count);
	tmp = ft_strnew(sizeof(tmp) * (ft_strlen(save) + 1));
	if (tmp == NULL)
		return (-1);
	tmp = ft_strcpy(tmp, &save[count + 1]);
	ft_strclr(save);
	save = ft_strcpy(save, tmp);
	free(tmp);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	char	*save[sizeof(fd)];

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL || BUFF_SIZE >= 10000000)
		return (-1);
	if (!save[fd] && (save[fd] = ft_strnew(sizeof(save[fd]) * 2))
			== NULL)
		return (-1);
	if ((save[fd] = read_file(fd, save[fd])) == NULL)
		return (-1);
	if (save[fd][0] == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (fill_save_line(save[fd], line) < 0)
		return (-1);
	return (1);
}
