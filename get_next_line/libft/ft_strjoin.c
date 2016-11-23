/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 21:05:39 by alex              #+#    #+#             */
/*   Updated: 2016/11/23 12:21:02 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	count;
	size_t	lens_s1;
	size_t	len_s2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_strnew(sizeof(char) * (lens_s1 + len_s2));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (count < lens_s1)
	{
		str[count] = s1[count];
		count++;
	}
	while (count < (lens_s1 + len_s2))
	{
		str[count] = s2[count - lens_s1];
		count++;
	}
	str[count] = '\0';
	return (str);
}
