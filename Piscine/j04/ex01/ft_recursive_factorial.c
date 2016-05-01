/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 09:57:42 by malexand          #+#    #+#             */
/*   Updated: 2015/07/14 19:54:51 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_recursive_factorial(int nb)
{
	if (nb > 2)
	{
		nb = nb * ft_recursive_factorial(nb - 1);
		return (nb);
	}
	else
		return (nb);
}
