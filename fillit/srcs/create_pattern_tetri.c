/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pattern_tetri.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:02:41 by malexand          #+#    #+#             */
/*   Updated: 2016/11/14 12:02:42 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/lib.h"

static	int		*get_pos_tetri(char *str)
{
	int		count;
	int		occu;
	int		*tab;

	tab = (int *)malloc(sizeof(int) * 4);
	if (tab == NULL)
		return (NULL);
	count = 0;
	occu = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '#')
		{
			tab[occu] = count;
			occu++;
		}
		count++;
	}
	return (tab);
}

static	int		get_width(char *str, int *tab)
{
	int		count;
	int		left;
	int		right;

	count = 0;
	left = tab[0] % 5;
	right = tab[0] % 5;
	while (count < 4)
	{
		if (tab[count] % 5 < left)
			left = tab[count] % 5;
		count++;
	}
	count = 0;
	while (count < 4)
	{
		if (tab[count] % 5 > right)
			right = tab[count] % 5;
		count++;
	}
	return ((right - left) + 1);
}

static	int		find_start(char *str)
{
	int count;
	int left;
	int heigth;

	count = 0;
	while (str[count] != '#')
		count++;
	left = count % 5;
	heigth = count / 5;
	while (str[count] != '\0')
	{
		if (str[count] == '#')
			if (count % 5 < left)
				left = count % 5;
		count++;
	}
	return (left + (heigth * 5));
}

static	char	*create_pattern(char *str, int width, int heigth, int count)
{
	int		i;
	int		j;
	char	*strnew;

	j = 0;
	i = 0;
	if ((strnew = (char *)malloc(sizeof(*strnew) * ((width + 1) * (heigth
			+ 1)))) == NULL)
		return (NULL);
	while (i < (width + 1) * heigth)
	{
		strnew[i] = str[count + j];
		i++;
		j++;
		if (j >= width)
		{
			count += 5;
			strnew[i] = '\n';
			i++;
			j = 0;
		}
	}
	strnew[i] = '\0';
	return (strnew);
}

char			*ft_form_tetri(char *str)
{
	int		*tab;
	int		width;
	int		heigth;
	char	*strnew;

	tab = get_pos_tetri(str);
	if (tab == NULL)
		return (NULL);
	heigth = ((tab[3] / 5) + 1) - ((tab[0] / 5) + 1) + 1;
	width = get_width(str, tab);
	strnew = create_pattern(str, width, heigth, find_start(str));
	free(tab);
	return (strnew);
}
