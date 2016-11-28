/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:29:48 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/24 20:20:07 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if ((tmp = (void *)malloc(sizeof(void) * size)))
	{
		ft_bzero(tmp, size);
		return (tmp);
	}
	return (NULL);
}
