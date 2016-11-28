/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 12:37:09 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/25 01:10:30 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*a;

	a = (unsigned char *)s;
	while (len > 0)
	{
		*a = (unsigned char)c;
		len--;
		a++;
	}
	return (s);
}
