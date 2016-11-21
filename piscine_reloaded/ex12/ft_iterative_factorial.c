/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:08:52 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 15:30:50 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		count;
	int		result;

	count = 0;
	result = 1;
	if (nb < 0)
		result = 0;
	else if (nb > 0)
	{
		while (count++ < nb)
		{
			result *= count;
		}
	}
	return (result);
}
