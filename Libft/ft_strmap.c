/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:46:35 by alex              #+#    #+#             */
/*   Updated: 2016/05/07 14:14:27 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	count;

	count = 0;
	if (s && f)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str == NULL)
			return(NULL);
		while(s[count])
		{
			str[count] = f(s[count]);
			count++;
		}
		str[count] = '\0';
		return(str);
	}
	else
		return (NULL);
}