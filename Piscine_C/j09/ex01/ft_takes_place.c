/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 18:03:35 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 00:21:46 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_exception(int hour)
{
	if (hour == 11)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "11.00 A.M. AND 12.00 P.M.", 25);
	}
	else if (hour == 23)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "11.00 P.M. AND 12.00 A.M.", 25);
	}
	if (hour == 12)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "12.00 P.M. AND 1.00 P.M.", 24);
	}
	if (hour == 24 || hour == 0)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		write(1, "12.00 A.M. AND 1.00 A.M", 24);
	}
}

void ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void ft_print(int hour)
{
	if (hour < 12 && hour != 0 && hour != 11)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		ft_putnbr(hour);
		write(1, ".00 A.M. AND ", 13);
		ft_putnbr(hour + 1);
		write(1, ".00 A.M.", 8);
	}
	else if (hour > 12 && hour != 24 && hour != 23)
	{
		write(1, "THE FOLLOWING TAKES PLACE BETWEEN ", 34);
		ft_putnbr(hour - 12);
		write(1, ".00 P.M. AND ", 13);
		ft_putnbr(hour + 1 - 12);
		write(1, ".00 P.M.", 8);
	}
}

void ft_takes_place(int hour)
{
	ft_exception(hour);
	ft_print(hour);
}
