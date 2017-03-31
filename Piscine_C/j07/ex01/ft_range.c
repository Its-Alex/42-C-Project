/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 13:22:18 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 22:31:10 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int 	*ft_range(int min, int max)
{
	int i;
	int *p;

	if (min >= max)
		return (0);
	i = 0;
	p = (int*)malloc(sizeof(max - min));
	while (min < max)
	{
		p[i] = min++;
		i++;
	}
	return (p);
}
