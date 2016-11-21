/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:58:40 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 15:55:39 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		count;
	int		src_size;
	char	*new_str;

	count = 0;
	src_size = 0;
	while (src[src_size])
		src_size++;
	new_str = (char*)malloc(sizeof(*new_str) * (src_size));
	if (new_str == NULL)
		return (NULL);
	while (count < src_size)
	{
		new_str[count] = src[count];
		count++;
	}
	new_str[src_size] = '\0';
	return (new_str);
}
