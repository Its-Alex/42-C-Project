/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:02:09 by malexand          #+#    #+#             */
/*   Updated: 2016/11/16 13:15:30 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fillit.h"

static	int		ft_formfile(const char *str, int i)
{
	int		line;

	while (*str)
	{
		line = 0;
		while (line++ < 4)
		{
			i = 0;
			while (i++ < 4)
			{
				if (*str != '.' && *str != '#')
					return (-1);
				str++;
			}
			if (*str != '\n')
				return (-1);
			str++;
		}
		if (*str != '\n' && *str != '\0')
			return (-1);
		if (*str == '\0')
			return (1);
		str++;
	}
	return (-1);
}

static	int		ft_nbtetri(const char *str)
{
	int		nb_tetri;

	nb_tetri = ft_strlen(str) / 21;
	if (nb_tetri + 1 > 26)
		return (-1);
	return (nb_tetri + 1);
}

static	int		ft_search(const char *str, int index, int *check)
{
	int		count;

	count = 0;
	if ((index - 1) >= 0)
		if (str[index - 1] == '#')
			count++;
	if ((index - 5) >= 0)
		if (str[index - 5] == '#')
			count++;
	if (str[index + 1] == '#')
		count++;
	if (str[index + 5] == '#')
		count++;
	if (count > 1)
		*check = 1;
	return (count);
}

static	int		ft_validtetri(const char *str)
{
	int		index;
	int		nb_sym;
	int		check;

	index = 0;
	nb_sym = 0;
	check = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
		{
			nb_sym++;
			if (ft_search(str, index, &check) <= 0)
				return (-1);
		}
		if (check_nbsynb((char *)str, index, &nb_sym, &check) == -1)
			return (-1);
		index++;
	}
	return (1);
}

int				ft_check_tetriminos(const char *str)
{
	int		i;

	i = 0;
	if (ft_strlen(str) > 21 * 27)
		return (-1);
	if (ft_formfile(str, i) < 0)
		return (-1);
	if (ft_validtetri(str) < 0)
		return (-1);
	return (ft_nbtetri(str));
}
