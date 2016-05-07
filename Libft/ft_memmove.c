/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:55:54 by alex              #+#    #+#             */
/*   Updated: 2016/05/06 22:55:49 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
	char 	*tmp;
	char 	*dest0;
	char 	*src0;
	size_t 	count;

	count 	= 0;
	tmp 	= (char *)malloc(sizeof(char) * n);
	src0 	= (char *)src;
	dest0 	= (char *)dest;
	if (dest == src || n == 0)
		return (dest);
	while (count < n)
	{
		tmp[count] = src0[count];
		count++;
	}
	count = 0;
	while (count < n)
	{
		dest0[count] = tmp[count];
		count++;
	}
	free(tmp);
	tmp = NULL;
	return (dest);
}
