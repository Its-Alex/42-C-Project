/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 13:18:33 by alex              #+#    #+#             */
/*   Updated: 2017/01/15 15:45:35 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
