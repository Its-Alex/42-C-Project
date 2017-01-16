/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 15:16:22 by alex              #+#    #+#             */
/*   Updated: 2017/01/15 15:45:36 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[count] == s2[count] && s1[count] && s2[count])
		count++;
	if (s1[count] == '\0' && s2[count] == '\0')
		return (1);
	else
		return (0);
}
