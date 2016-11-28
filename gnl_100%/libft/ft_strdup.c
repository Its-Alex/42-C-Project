/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 16:43:13 by vacrozet          #+#    #+#             */
/*   Updated: 2016/11/09 17:21:39 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (0);
	if (tmp)
	{
		ft_strcpy(tmp, str);
		return (tmp);
	}
	else
		return (NULL);
}
