/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 11:55:43 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/23 18:26:36 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*dst;
	unsigned int	i;

	source = (unsigned char *)src;
	dst = (unsigned char *)dest;
	i = 0;
	if (dst > source)
		while (0 < n)
		{
			dst[n - 1] = source[n - 1];
			n--;
		}
	else
		while (i < n)
		{
			dst[i] = source[i];
			i++;
		}
	return (dst);
}
