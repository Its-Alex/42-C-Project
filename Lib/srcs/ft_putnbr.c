/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 23:29:37 by malexand          #+#    #+#             */
/*   Updated: 2016/05/01 18:40:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putchar(char c, int output);

void ft_putnbr(int nb, int output)
{
	if (nb < 0)
	{
		ft_putchar('-', output);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, output);
		ft_putnbr(nb % 10, output);
	}
	else
		ft_putchar(nb + '0', output);
}
