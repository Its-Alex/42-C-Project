/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 00:40:18 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/25 00:53:51 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	unsigned int	i;

	i = -1;
	if (s == NULL)
		return ;
	while (s[++i])
		ft_putchar(s[i]);
}
