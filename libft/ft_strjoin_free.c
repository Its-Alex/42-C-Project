/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 10:32:41 by malexand          #+#    #+#             */
/*   Updated: 2016/11/16 15:46:44 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, const char *s2)
{
	size_t	count;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (count < ft_strlen(s1))
	{
		str[count] = s1[count];
		count++;
	}
	while (count < (ft_strlen(s1) + ft_strlen(s2)))
	{
		str[count] = s2[count - ft_strlen(s1)];
		count++;
	}
	free(s1);
	str[count] = '\0';
	return (str);
}
