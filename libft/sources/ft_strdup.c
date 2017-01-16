/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:51:55 by malexand          #+#    #+#             */
/*   Updated: 2017/01/15 15:45:36 by skyzie           ###   ########.fr       */
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
	new_str = ft_strnew(src_size);
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
