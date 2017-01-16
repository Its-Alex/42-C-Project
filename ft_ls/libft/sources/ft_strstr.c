/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:08:32 by malexand          #+#    #+#             */
/*   Updated: 2017/01/15 15:45:40 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		count_big;
	int		count_little;

	count_big = 0;
	count_little = 0;
	if (little[0] == '\0')
		return (char *)(big);
	while (big[count_big] != '\0')
	{
		if (big[count_big] == little[0])
			while (big[count_big + count_little] == little[count_little]
					&& little[count_little] != '\0'
					&& big[count_big + count_little] != '\0')
				count_little++;
		if (count_little == (int)ft_strlen(little))
			return ((char *)big + count_big);
		else
			count_little = 0;
		count_big++;
	}
	return (NULL);
}
