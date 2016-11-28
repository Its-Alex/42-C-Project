/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 23:42:12 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/09 17:24:27 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;
	unsigned int	j;

	if (s && f)
	{
		j = ft_strlen((char *)s);
		i = -1;
		if (!(tmp = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
		while (s[++i])
			tmp[i] = f(i, s[i]);
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
