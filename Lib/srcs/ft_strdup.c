/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:51:55 by malexand          #+#    #+#             */
/*   Updated: 2016/05/01 18:40:06 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(char *src)
{
	int   i;
	char *p;
	int   size;

	size = 0;
	i    = 0;
	if (src[i] == '\0')
		return (p = 0);
	while (src[size] != '\0')
		size++;
	p = (char *)(malloc(sizeof(char) * size));
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
