/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 00:45:48 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/09 17:19:04 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putchar(unsigned char c)
{
	unsigned int tmp;

	if (c < 128)
		write(1, &c, 1);
	else
	{
		tmp = (192 | (c >> 6));
		write(1, &tmp, 1);
		tmp = (128 | (c & 63));
		write(1, &tmp, 1);
	}
}
