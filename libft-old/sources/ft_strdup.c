/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:51:55 by malexand          #+#    #+#             */
/*   Updated: 2016/11/22 15:47:48 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *src)
{
	int		count;
	int		src_size;
	char	*new_str;

	count = 0;
	src_size = ft_strlen(src);
	new_str = ft_strnew(sizeof(*new_str) * (src_size + 1) - 1);
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
