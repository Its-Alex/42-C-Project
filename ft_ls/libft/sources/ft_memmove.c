/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 20:55:54 by alex              #+#    #+#             */
/*   Updated: 2017/01/15 15:45:32 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	char	*dest0;
	char	*src0;
	size_t	count;

	count = 0;
	src0 = (char *)src;
	dest0 = (char *)dest;
	if (dest == src || n == 0 ||
			(tmp = (char *)malloc(sizeof(char) * n)) == NULL)
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
