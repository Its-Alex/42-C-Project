/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 20:13:59 by alex              #+#    #+#             */
/*   Updated: 2016/05/07 21:43:35 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t count;
	char  *str;

	if (ft_strlen(s) < start + len || !s)
		return (NULL);
	count = 0;
	str   = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (count < len)
	{
		str[count] = s[count + start];
		count++;
	}
	str[count] = '\0';
	return (str);
}
