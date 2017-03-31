/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 19:03:47 by malexand          #+#    #+#             */
/*   Updated: 2015/07/15 21:45:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (str[0] == '\0')
		return (1);
	while (str[size] != '\0')
		size++;
	while (str[i] != '\0' && ((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')))
	{
		i++;
	}
	if (i == size)
		return (1);
	else
		return (0);
}
