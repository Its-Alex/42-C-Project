/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 10:57:55 by malexand          #+#    #+#             */
/*   Updated: 2015/07/14 19:56:10 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	else if (power == 1 || nb == 0)
		return (nb);
	else if (power > 0)
		return (0);
	if (power > 1)
	{
		nb = nb * ft_recursive_power(nb, power - 1);
		return (nb);
	}
	return (nb);
}
