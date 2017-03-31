/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colle04.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 13:47:54 by malexand          #+#    #+#             */
/*   Updated: 2015/07/26 18:25:22 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_extremum_up04(int x, char *tab, int k)
{
	int i;

	i = 0;
	tab[k] = 'A';
	k++;
	while (i++ < x - 2)
	{
		tab[k] = 'B';
		k++;
	}
	if (x != 1)
	{
		tab[k] = 'C';
		k++;
	}
	tab[k] = '\n';
	k++;
	return (k);
}

int		ft_extremum_down04(int x, char *tab, int k)
{
	int i;

	i = 0;
	tab[k] = 'C';
	k++;
	while (i++ < x - 2)
	{
		tab[k] = 'B';
		k++;
	}
	if (x != 1)
	{
		tab[k] = 'A';
		k++;
	}
	tab[k] = '\n';
	k++;
	return (k);
}

int		ft_center04(int x, int y, char *tab, int k)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y - 2)
	{
		tab[k] = 'B';
		k++;
		if (x != 1)
		{
			j = 0;
			while (j++ < x - 2)
			{
				tab[k] = ' ';
				k++;
			}
			tab[k] = 'B';
			k++;
		}
		tab[k] = '\n';
		k++;
		i++;
	}
	return (k);
}

void	colle04(char *tab, int x, int y)
{
	int i;
	int k;

	k = 0;
	tab[0] = '\0';
	if (x > 0 && y > 0)
	{
		k = ft_extremum_up04(x, tab, k);
		i = 0;
		k = ft_center04(x, y, tab, k);
		i = 0;
		if (y != 1)
			k = ft_extremum_down04(x, tab, k);
		tab[k] = '\0';
	}
}
