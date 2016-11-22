/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 13:36:53 by root              #+#    #+#             */
/*   Updated: 2016/11/22 22:05:40 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		ft_getlen(int value)
{
	int		len;

	len = 0;
	while (value != 0)
	{
		value = value / 10;
		len++;
	}
	return (len);
}

static	int		ft_getstr(int value, char *str)
{
	int		rest;
	int		count;

	rest = 0;
	count = 0;
	while (value != 0)
	{
		rest = value % 10;
		str[count++] = rest + '0';
		value = value / 10;
	}
	return (count);
}

static	int		is_negative(int *value)
{
	int		sign;

	sign = 1;
	if (*value < 0)
	{
		*value = -*value;
		sign = -1;
	}
	return (sign);
}

char			*ft_itoa(int value)
{
	int		sign;
	int		count;
	char	*str;

	count = 0;
	sign = is_negative(&value);
	if (value == 0 || value == -0)
		return ("0");
	if (value == -2147483648)
		return ("-2147483648");
	if (value == 2147483647)
		return ("2147483647");
	if ((str = ft_strnew(sizeof(char) * (ft_getlen(value) +
			1))) == NULL)
		return (NULL);
	count = ft_getstr(value, str);
	if (sign < 0)
		str[count++] = '-';
	str[count] = '\0';
	ft_strrev(str);
	return (str);
}
