/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:32:30 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 15:31:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int result;

	result = 0;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	result = ft_recursive_factorial(nb - 1);
	result = result * nb;
	return (result);
}
