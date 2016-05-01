/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sganon <sganon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/18 09:46:16 by sganon            #+#    #+#             */
/*   Updated: 2015/07/19 22:41:55 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
int 	ft_check(char **argv);
int		ft_scan(char **tab1, char **tab2);
int		ft_recursive_front(char **argv, int pos);
char	**ft_str_strdup(char **argv);
int		ft_recursive_back(char **argv, int pos);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_checkchar(char **argv)
{
	int x;
	int y;
	int cmpt;

	y = 0;
	cmpt = 0;
	while (y <= 8)
	{
		x = 0;
		while (x <= 8)
		{
			if (argv[y][x] == '.' || (argv[y][x] > '0' && argv[y][x] <= '9'))
			{
				if (argv[y][x] > '0' && argv[y][x] <= '9')
					cmpt++;
				x++;
			}
			else
				return (0);
		}
		y++;
	}
	if (cmpt < 17 || (y * x) != 81)
		return (0);
	return (1);
}

void	ft_putsudoku(char **argv)
{
	int x;
	int y;

	y = 0;
	while (y <= 8)
	{
		x = 0;
		while (argv[y][x] != '\0')
		{
			ft_putchar(argv[y][x]);
			ft_putchar(' ');
			x++;
		}
		y++;
		ft_putchar('\n');
	}
}

int		main(int argc, char **argv)
{
	char **tab1;
	char **tab2;
	
	tab1 = ft_str_strdup(argv);
	tab2 = ft_str_strdup(argv);
	ft_putsudoku(tab1);
	if (ft_checkchar(tab1) && argc == 10 && ft_check(tab1))
	{
		ft_recursive_front(tab1, 0);
		ft_putsudoku(tab1);
		/*ft_putchar('\n');
		ft_recursive_back(tab2, 80);
		if (ft_check(tab1) && ft_check(tab2))
		{
			if (ft_scan(tab1, tab2))
				ft_putsudoku(tab1);
		}
		else
			ft_putstr("Erreur\n");*/
	}
	else
		ft_putstr("Erreur\n");
	return (0);
}
