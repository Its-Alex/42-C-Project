/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 19:00:15 by alex              #+#    #+#             */
/*   Updated: 2016/05/01 19:02:57 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	size_t count;
	char  *dest;

	dest  = (char*)s;
	count = 0;
	for (; count <= n; count++)
	{
		dest[count] = 0;
	}
}
