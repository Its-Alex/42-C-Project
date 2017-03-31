/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/12 18:03:53 by malexand          #+#    #+#             */
/*   Updated: 2015/07/12 19:03:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void sastantua(int size)
{
	int i;
	int space;
	int tmp;
	int e;
	int tmpe;
	
	i = 0;
	space = size * 2;
	tmp = space;
	e = 1;
	tmpe = e;
	while (i++ < size)
	{
		while (space-- != 0)
			ft_putchar(' ');
		ft_putchar('/');
		while (e-- != 0)
			ft_putchar('*');
		ft_putchar('\\');
		ft_putchar('\n');

		space = tmp - 1;
		e = 3;
		while (space-- != 0)
			ft_putchar(' ');
		ft_putchar('/');
		while (e-- != 0)
			ft_putchar('*');
		ft_putchar('\\');
		ft_putchar('\n');

		space = tmp - 2;
		e += 6;
		while (space-- != 0)
			ft_putchar(' ');
		ft_putchar('/');
		while (e-- != 0)
			ft_putchar('*');
		ft_putchar('\\');
		ft_putchar('\n');
	}
}

int main(void)
{
	sastantua(1);
	return (0);
}
