/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 14:21:14 by malexand          #+#    #+#             */
/*   Updated: 2015/07/21 15:06:45 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*p;
	int		size;

	if (src[i] == '\0')
		return (p = 0);
	while (src[size] != '\0')
		size++;
	i = 0;
	p = (char *)(malloc(sizeof(char) * size));
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	return (p);
}

struct s_stock_par *ft_param_to_tab(int ac, char **av)
{
	struct s_stock_par *tab;
	int i;

	tab = (struct s_stock_par*)malloc(sizeof(tab) * ac);
	while (i < ac)
	{
		x = 0; 
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		while (av[i][x] >= '\0')
			x++;
		tab[i].size_param = x;
		tab[i].tab = ft_split_whitespaces(av[i]);
	}
}
