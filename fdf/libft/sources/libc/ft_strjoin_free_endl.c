/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_endl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:19:35 by malexand          #+#    #+#             */
/*   Updated: 2016/11/24 13:57:33 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static	char	*putend(char *str, int count)
{
	str[count++] = '\n';
	str[count] = '\0';
	return (str);
}

char			*ft_strjoin_free_endl(char *s1, const char *s2)
{
	size_t	count;
	size_t	len[2];
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	str = ft_strnew(sizeof(char) * (len[0] + len[1] + 1));
	if (str == NULL)
		return (NULL);
	count = 0;
	while (count < len[0])
	{
		str[count] = s1[count];
		count++;
	}
	while (count < (len[0] + len[1]))
	{
		str[count] = s2[count - len[0]];
		count++;
	}
	free(s1);
	return (putend(str, count));
}
