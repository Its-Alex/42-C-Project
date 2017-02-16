/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:49:20 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 12:50:33 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

static	char		*read_file(const int fd, char *str)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ret = 0;
	while (!(ft_strchr(str, '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(tmp, buf)))
			return (NULL);
		free(tmp);
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
	tmp = ft_strnew(sizeof(tmp) * (ft_strlen(save)));
	if (tmp == NULL)
		return (-1);
	tmp = ft_strcpy(tmp, &save[count + 1]);
	ft_strclr(save);
	save = ft_strcpy(save, tmp);
	free(tmp);
	return (1);
}

static t_list		*find_fd(t_list *lst, int fd)
{
	t_list	*tmplst;
	char	**tmp;
	char	*file;

	tmplst = lst;
	file = ft_itoa(fd);
	while (tmplst)
	{
		tmp = ft_strsplit(tmplst->content, ' ');
		if (ft_strcmp(tmp[0], file) == 0)
			break ;
		tmplst = tmplst->next;
	}
	ft_freetab(tmp);
	ft_strdel(&file);
	return (tmplst);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*lst;
	t_list			*elem;

	if (BUFF_SIZE <= 0 || fd < 0 || fd > INT_MAX || line == NULL
		|| BUFF_SIZE >= 1000000)
		return (-1);
	if (lst == NULL)
	{
		lst = ft_lstnew(ft_strnew((size_t)ft_itoa(fd)), ft_strlen(ft_itoa(fd)));
		elem = lst;
	}
	else
		elem = find_fd(lst, fd);
	if ((elem->content = read_file(fd, (char*)(elem->content))) == NULL)
		return (-1);
	if (elem->content == '\0')
	{
		*line = NULL;
		return (0);
	}
	if (fill_save_line(elem->content, line) < 0)
		return (-1);
	return (1);
}
