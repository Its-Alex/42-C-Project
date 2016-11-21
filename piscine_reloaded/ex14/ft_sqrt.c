/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:44:42 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 15:34:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int		result;
	int		count;

	result = 0;
	count = 0;
	while (result < nb)
	{
		result = count;
		result *= result;
		if (result == nb)
			return (count);
		count++;
	}
	return (0);
}
