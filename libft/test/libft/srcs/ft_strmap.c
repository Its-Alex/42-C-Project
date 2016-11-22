/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:46:35 by alex              #+#    #+#             */
/*   Updated: 2016/11/22 16:58:55 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	size_t	count;

	count = 0;
	if (!s || !f)
		return (NULL);
	str = ft_strnew(sizeof(char) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	while (s[count])
	{
		str[count] = f(s[count]);
		count++;
	}
	str[count] = '\0';
	return (str);
}
