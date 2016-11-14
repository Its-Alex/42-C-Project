/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:02:09 by malexand          #+#    #+#             */
/*   Updated: 2016/11/11 18:30:12 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lib.h"

static	int		ft_formfile(const char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 4)
		{
			if (str[i] != '.' && str[i] != '#')
				return (-1);
			j++;
			i++;
		}
		if (str[i] != '\n' && str[i] != '0')
			return (-1);
		i++;
		if (str[i] == '\n')
			i++;
		if (str[i + 1] == '\0')
			return (1);
	}
	return (1);
}

static	int		ft_nbtetri(const char *str)
{
	int		nb_tetri;

	nb_tetri = 0;
	while (*str)
	{
		str = str + 21;
		nb_tetri++;
	}
	if (nb_tetri - 1 > 26)
		return (-1);
	return (nb_tetri - 1);
}

static	int		ft_search(const char *str, int index)
{
	if ((index - 1) > 0)
		if (str[index - 1] == '#')
			return (1);
	if ((index - 5) > 0)
		if (str[index - 5] == '#')
			return (1);
	if (str[index + 1] == '#')
		return (1);
	if (str[index + 5] == '#')
		return (1);
	return (-1);
}

static	int		ft_validtetri(const char *str)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '#')
		{
			count++;
			if ((ft_search(str, index)) == -1)
				return (-1);
		}
		if (count > 4)
			return (-1);
		if (str[index] == '\n' && str[index + 1] == '\n')
			count = 0;
		index++;
	}
	return (1);
}

int				ft_check_tetriminos(const char *str)
{
	if (ft_strlen(str) > 21 * 27)
		return (-1);
	if (ft_formfile(str) < 0)
		return (-1);
	if (ft_validtetri(str) < 0)
		return (-1);
	return (ft_nbtetri(str));
}
