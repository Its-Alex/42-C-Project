/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:25:25 by malexand          #+#    #+#             */
/*   Updated: 2016/11/15 18:10:43 by tglandai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fillit.h"

int				check_nbsynb(char *str, int index, int *nb_sym, int *check)
{
	if ((str[index] == '\n' && str[index + 1] == '\n') ||
		(str[index] == '\n' && str[index + 1] == '\0'))
	{
		if (*nb_sym != 4 || *check != 1)
			return (-1);
		else
		{
			*check = 0;
			*nb_sym = 0;
		}
	}
	return (1);
}

int				ft_isupper(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

int				check_valid_point(char *tab, char **tryresult, int i, int j)
{
	int		h;
	int		l;
	int		k;
	int		m;

	h = 0;
	l = 0;
	m = 0;
	while (ft_isupper(tab[h]) == 0 && tab[h] != '\0')
		h++;
	while (tab[h + l] != '\0')
	{
		if (tab[h + l] == '\n')
			m++;
		if (ft_isupper(tab[h + l]) == 1)
		{
			k = j + l - (m * 5);
			if (k < 0 || (i + m) >= (int)ft_strlen(tryresult[0]) ||
					k >= (int)ft_strlen(tryresult[0]) ||
					tryresult[i + m][k] != '.')
				return (0);
		}
		l++;
	}
	return (1);
}

char			**form_tetri(char **tetri, char *str)
{
	int		nb_tetri;
	int		count;

	count = 0;
	if ((nb_tetri = ft_check_tetriminos(str)) <= 0)
		return (NULL);
	if ((tetri = (char **)malloc(sizeof(*tetri) * nb_tetri + 1)) == NULL)
		return (NULL);
	while (count < nb_tetri)
	{
		if ((tetri[count] = ft_strsub(str, count * 21,
				19)) == NULL)
			ft_free_array(tetri);
		count++;
	}
	tetri[count] = NULL;
	free(str);
	if (tetri == NULL)
		return (NULL);
	return (tetri);
}

int				main(int argc, char const **argv)
{
	char	**tetri;
	char	*str;
	int		lenstr;

	if (argc != 2)
		ft_putstr("Error use ./fillit file\n");
	else
	{
		if ((str = ft_create_str(argv[1])) == NULL)
			return (0);
		lenstr = ft_strlen(str);
		tetri = form_tetri(tetri, str);
		if (tetri && lenstr > 0)
		{
			holy_resolve(tetri, (lenstr + 1) / 21);
			if (tetri)
				ft_free_array(tetri);
		}
		else
			ft_putstr("error\n");
	}
	return (0);
}
