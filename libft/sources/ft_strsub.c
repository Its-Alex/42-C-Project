/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 20:13:59 by alex              #+#    #+#             */
/*   Updated: 2017/01/15 15:45:40 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	count;

	count = 0;
	if (!s || len > ft_strlen(s) || start > ft_strlen(s))
		return (NULL);
	if ((str = (char*)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	while (start + count < start + len)
	{
		str[count] = s[start + count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
