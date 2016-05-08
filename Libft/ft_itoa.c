/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 23:15:57 by alex              #+#    #+#             */
/*   Updated: 2016/05/07 19:51:11 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char        *ft_itoa(int value, char *str, int base)
{
	int is_negative;
	int count;
	int rest;

	count       = 0;
	is_negative = 0;
	if (value == 0)
	{
		str[count++] = '0';
		str[count]   = '\0';
	}
	if (value < 0 && base == 10)
	{
		value       = -value;
		is_negative = 1;
	}
	while (value != 0)
	{
		rest         = value % base;
		str[count++] = (rest > 10) ? (rest - 10) + 'a' : rest + '0';
		value        = value / base;
	}
	if (is_negative)
		str[count++] = '-';
	str[count] = '\0';
	ft_strrev(str);
	return (str);
}
