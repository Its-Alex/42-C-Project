/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 17:33:25 by root              #+#    #+#             */
/*   Updated: 2017/01/15 15:45:38 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (0);
	while ((unsigned char)s1[count] == (unsigned char)s2[count] &&
			(unsigned char)s1[count] != '\0' &&
			(unsigned char)s2[count] != '\0' && num > count)
		count++;
	if (((unsigned char)s1[count] == '\0' || (unsigned char)s2[count] == '\0')
			&& count == num)
		return (0);
	if ((unsigned char)s1[count - 1] == (unsigned char)s2[count - 1] &&
			count == num)
		return (0);
	return ((unsigned char)s1[count] - (unsigned char)s2[count]);
}
