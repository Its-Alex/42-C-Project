/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:01:05 by malexand          #+#    #+#             */
/*   Updated: 2015/07/15 08:38:58 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_iterative_factorial(int nb)
{
	int i;

	if (nb > 12 || nb < 0)
		return (0);
	i = nb;
	while (i != 2)
	{
		i--;
		nb = nb * (i);
	}
	return (nb);
}
