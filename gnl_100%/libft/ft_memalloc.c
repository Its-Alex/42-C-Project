/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 19:29:48 by malexand          #+#    #+#             */
/*   Updated: 2016/08/24 20:20:07 by malexand         ###   ########.fr       */
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
