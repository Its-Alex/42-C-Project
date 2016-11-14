/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:39:13 by malexand          #+#    #+#             */
/*   Updated: 2016/11/11 14:39:15 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lib.h"

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
		{
			free(str);
			return (NULL);
		}
	}
	if (ret == -1)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	return (str);
}

static	char	*ft_create_str(const char *name_file)
{
	int		fd;
	char	*str;

	if ((fd = open(name_file, O_RDONLY)) < 0)
		return (NULL);
	str = ft_readfile(fd);
	if (close(fd) == -1)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	return (str);
}

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

char			**ft_split_tetri(const char *name_file)
{
	char	**tetri;
	char	*str;
	int		nb_tetri;
	int		count;

	count = 0;
	if ((str = ft_create_str(name_file)) == NULL)
		return (NULL);
	if ((nb_tetri = ft_check_tetriminos(str)) <= 0)
		return (NULL);
	if ((tetri = (char **)malloc(sizeof(*tetri) * nb_tetri + 1)) == NULL)
		return (NULL);
	while (count < nb_tetri)
	{
		if (ft_form_tetri((tetri[count] = ft_strsub(str, count * 21,
				20))) == NULL)
			ft_free_array(tetri);
		count++;
	}
	tetri[count] = NULL;
	free(str);
	if(tetri == NULL)
		return (NULL);
	return (tetri);
}
