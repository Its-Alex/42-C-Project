/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/11/24 17:30:07 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"

static	char	*error(char *str)
{
	ft_strdel(&str);
	ft_putstr_color("Error \x1B[0m: ", RED);
	perror("");
	return (NULL);
}

static	int		**atoi_3d(char ***tabstr)
{
	int		line;
	int		column;
	int		count;
	int		**tabint;

	line = 0;
	column = 0;
	count = 0;
	while (tabstr[line])
		line++;
	tabint = (int **)ft_memalloc(sizeof(*tabint) * line + 1);
	ft_putstr_color("Salut\n", RED);
	while (count < line)
	{
		column = 0;
		while (tabstr[count][column])
		{
			ft_putendl(tabstr[count][column]);
			ft_putstr_color("Salut\n", RED);
			tabint[count][column] = (int)malloc(sizeof(int));
			tabint[count][column] = ft_atoi(tabstr[count][column]);
			ft_putendl(tabstr[count][column]);
			column++;
		}
		count++;
	}
	ft_putstr_color("Salut\n", RED);
	tabint[count] = NULL;
	count = 0;
	while (tabint[count] != NULL)
	{
		column = 0;
		while (tabint[count][column])
		{
			ft_putnbr(tabint[count][column]);
			column++;
		}
		count++;
	}
	return (tabint);
	// int		line;
	// int		column;
	// line = 0;
	// column = 0;
	// while (array[line])
	// {
	// 	column = 0;
	// 	while (array[line][column])
	// 	{
	// 		ft_putstr(array[line][column]);
	// 		ft_putstr(" ");
	// 		column++;
	// 	}
	// 	ft_putendl("");
	// 	line++;
	// }
}

static	char	*parse_str(char *str)
{
	char	***str_parse;

	str_parse = parse_array_3d(str, '\n', ' ');
	putarray_3d(str_parse);
	atoi_3d(str_parse);
	return (str);
}

char			*parse_file(const char *file_name)
{
	int		fd;
	int		ret;
	char	*tmp;
	char	*str;

	fd = 0;
	ret = 0;
	str = (char*)malloc(sizeof(char));
	str[0] = '\0';
	if ((fd = open(file_name, O_RDONLY)) < 0)
		return (error(str));
	while ((ret = get_next_line(fd, &tmp)) == 1)
		str = ft_strjoin_free_endl(str, tmp);
	if (ret == -1)
		return (error(str));
	ft_strdel(&tmp);
	if (close(fd) < 0)
		return (error(str));
	parse_str(str);
	return (NULL);
}
