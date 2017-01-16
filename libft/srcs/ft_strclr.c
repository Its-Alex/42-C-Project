/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:18:33 by alex              #+#    #+#             */
/*   Updated: 2017/01/16 23:17:24 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

void	ft_strclr(char *s)
{
	size_t	count;
	size_t	size;

	count = 0;
	if (s)
	{
		size = ft_strlen(s);
		while (count <= size)
			s[count++] = '\0';
	}
}
