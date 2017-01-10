/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:41:33 by alex              #+#    #+#             */
/*   Updated: 2016/11/22 15:47:49 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	count;

	count = 0;
	if (s && f)
	{
		while (s[count])
		{
			f(count, &s[count]);
			count++;
		}
	}
}
