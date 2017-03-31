/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 13:48:57 by malexand          #+#    #+#             */
/*   Updated: 2015/07/21 14:26:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *tab_back;

	tab_back = (int*)malloc(sizeof(int) * length);
	i = 0;
	while (i < length)
	{
		tab_back[i] = tab[i];
		f(tab_back[i]);
		i++;
	}
	return (tab_back);
}
