/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 15:55:11 by sganon            #+#    #+#             */
/*   Updated: 2015/07/19 23:04:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putstr(char *str);
void ft_putchar (char c);

int		ft_check_line(char **argv, int y, char k)
{
	int x;

	x = 0;
	while (x  <= 8)
	{
		if (argv[y][x] == k)
		{
			return (0);
		}
		x++;
	}
	return (1);
}

int		ft_check_column(char **argv, int x, char k)
{
	int y;

	y = 0;
	while (y <= 8)
	{
		if (argv[y][x] == k)
			return (0);
		y++;
	}
	return (1);
}

int		ft_check_bloc(char **argv, char k, int y, int x)
{
	int x2;
	int y2;

	y = y - (y % 3);
	x = x - (x % 3);
	y2 = y + 3;
	x2 = x + 3;
	while (y < y2)
	{
		while(x < x2)
		{
			if (argv[y][x] == k)
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int		ft_recursive_front(char **argv, int pos)
{
	char k;
	int y;
	int x;

	y = pos / 9;
	x = pos % 9;
	k = '1';
	if (pos > 80)
		return (1);
	if (argv[y][x] != '.')
		return (ft_recursive_front(argv, pos + 1));
	while (k <= '9')
	{
		if (ft_check_line(argv, y, k) && ft_check_column(argv, x, k) 
				&& ft_check_bloc(argv, k, y, x))
		{
			argv[y][x] = k;
			if (ft_recursive_front(argv, pos + 1) == 1)
				return (1);
		}
		k++;
	}
	argv[y][x] = '.';
	return (0);
}

int		ft_recursive_back(char **argv, int pos)
{
	char k;
	int x;
	int y;

	y = pos / 9;
	x = pos % 9;
	k = '1';
	if (pos < 0)
		return (1);
	if (argv[y][x] != '.')
		return (ft_recursive_back(argv, pos - 1));
	while (k <= '9')
	{
		if (ft_check_line(argv, y, k) && ft_check_column(argv, x, k) 
				&& ft_check_bloc(argv, k, y, x))
			{
				argv[y][x] = k;
				if (ft_recursive_back(argv, pos - 1) == 1)
					return (1);
			}
		k++;
	}
	argv[y][x] = '.';
	return (0);
}
