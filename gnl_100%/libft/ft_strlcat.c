/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 14:25:13 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/14 15:06:09 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < len && dest[i])
		i++;
	if (len == i)
		return (len + ft_strlen(src));
	j = i;
	while (src[i - j] && i < len - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < len)
		dest[i] = '\0';
	return (j + ft_strlen(src));
}
