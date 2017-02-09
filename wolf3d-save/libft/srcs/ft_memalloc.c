/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:00:06 by alex              #+#    #+#             */
/*   Updated: 2017/01/16 23:17:20 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*data;
	size_t	count;

	count = 0;
	if ((data = (char *)malloc(size)) == NULL)
		return (NULL);
	while (count < size)
		data[count++] = 0;
	return ((void*)data);
}
