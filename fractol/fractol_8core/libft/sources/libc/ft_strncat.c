/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:55:13 by malexand          #+#    #+#             */
/*   Updated: 2016/11/22 15:47:53 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	count;
	size_t	len;

	count = 0;
	len = ft_strlen(dest);
	while (src[count] != '\0' && count < n)
	{
		dest[len + count] = src[count];
		count++;
	}
	dest[len + count] = '\0';
	return (dest);
}
