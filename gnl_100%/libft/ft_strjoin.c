/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 11:58:36 by malexand          #+#    #+#             */
/*   Updated: 2016/11/09 17:22:28 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	k;
	unsigned int	n;

	k = -1;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) *
	ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[++k])
		str[k] = s1[k];
	while (s2[n])
	{
		str[k] = s2[n];
		k++;
		n++;
	}
	str[k] = '\0';
	return (str);
}
