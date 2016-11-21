/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:23:34 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 16:01:28 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int		count;
	int		len;
	int		*tab;

	count = 0;
	len = max - min;
	if (min > max || len <= 0)
		return (NULL);
	tab = (int *)malloc(sizeof(int) * len);
	while (count < len)
	{
		tab[count] = count + min;
		count++;
	}
	return (tab);
}
