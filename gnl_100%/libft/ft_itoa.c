/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 20:03:56 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/14 15:19:03 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_itoa_too(int n, size_t *len, int *nbr)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*nbr = 1;
	while (n / *nbr < -9)
	{
		*nbr *= 10;
		*len += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		len;
	size_t		i;
	int			nbr;
	char		*str;

	ft_itoa_too(n, &len, &nbr);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
	}
	if (n > 0)
		n = -n;
	while (nbr >= 1)
	{
		str[i++] = -(n / nbr % 10) + 48;
		nbr /= 10;
	}
	str[i] = '\0';
	return (str);
}
