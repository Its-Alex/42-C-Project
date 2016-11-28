/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:06:18 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/23 14:39:31 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *source;
	unsigned char *dest;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	while (n > 0)
	{
		*dest = *source;
		n--;
		dest++;
		source++;
	}
	return (dst);
}
