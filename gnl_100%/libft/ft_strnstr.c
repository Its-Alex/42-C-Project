/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 20:12:23 by malexand          #+#    #+#             */
/*   Updated: 2016/11/09 17:26:52 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(char *place, char *search, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*search)
		return ((char *)place);
	while (*place && len > 0)
	{
		if (len < ft_strlen(search))
			return (NULL);
		j = 0;
		k = i;
		while (place[k] == search[j] && search[j] && place[k])
		{
			j++;
			k++;
		}
		if (search[j] == '\0')
			return ((char *)place + i);
		len--;
		place++;
	}
	return (NULL);
}
