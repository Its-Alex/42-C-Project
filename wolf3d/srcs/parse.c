/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:50:43 by malexand          #+#    #+#             */
/*   Updated: 2017/02/21 11:34:50 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int			check_str(char *str)
{
	int			count;

	count = 0;
	while (str[count])
	{
		if (str[count] != '0' && str[count] != '1' && str[count] != '2'
				&& str[count] != '4' && str[count] != ' ' && str[count] != '\n')
			return (-1);
		count++;
	}
	if (count <= 10)
		return (-1);
	return (0);
}

static char			***parse_array_3d(char *str, char carac1, char carac2)
{
	int		len;
	int		count;
	char	**split;
	char	***parse;

	len = 0;
	count = 0;
	split = ft_strsplit(str, carac1);
	while (split[len])
		len++;
	parse = (char ***)ft_memalloc(sizeof(*parse) * (len + 1));
	while (count < len)
	{
		parse[count] = ft_strsplit(split[count], carac2);
		ft_strdel(&split[count]);
		count++;
	}
	parse[count] = NULL;
	free(split);
	return (parse);
}

static void			get_length(t_map **map)
{
	int		line;
	int		column;
	int		save;

	line = 0;
	save = 0;
	column = 0;
	while ((*map)->mapget[line])
	{
		if (column >= save)
			save = column;
		column = 0;
		while ((*map)->mapget[line][column])
		{
			column++;
		}
		line++;
	}
	if (save > 50 || line > 50)
		error(1, 0, "Map reach limits!");
	(*map)->column = save;
	(*map)->line = line;
}

static char			*take_str(char *av, char *str)
{
	int		fd;
	int		ret;
	char	*tmp;

	fd = 0;
	ret = 0;
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	if ((fd = open(av, O_RDONLY)) < 0)
		error(1, 1, "");
	while ((ret = get_next_line(fd, &tmp)) == 1)
	{
		if (check_str(tmp) == -1)
			return (NULL);
		str = ft_strjoin_free(str, tmp);
		str = ft_strjoin_free(str, "\n");
		ft_strdel(&tmp);
	}
	if (ret == -1)
		error(1, 1, "");
	if (str[0] == '\0')
		error(1, 0, "Map empty!");
	if (close(fd) < 0)
		error(1, 1, "");
	return (str);
}

char				***get_map(t_map **map, char *file)
{
	char	*str;

	str = NULL;
	str = take_str(file, str);
	if (str == NULL)
		error(1, 0, "Bad map format!");
	if (check_format(str, 0, 0) == -1)
		error(1, 0, "Line numbers must be the same!");
	(*map)->mapget = parse_array_3d(str, '\n', ' ');
	ft_strdel(&str);
	if ((*map)->mapget == NULL)
		error(1, 0, "Bad parsing!");
	get_length(map);
	return ((*map)->mapget);
}
