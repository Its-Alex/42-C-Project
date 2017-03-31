/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 17:01:02 by malexand          #+#    #+#             */
/*   Updated: 2015/07/21 22:04:55 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		sort;

	i = 0;
	sort = 0;
	while (sort == 0 && i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			sort = -1;
		if (f(tab[i], tab[i + 1]) > 0)
			sort = 1;
		i++;
	}
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0 && sort == -1)
			return (0);
		if (f(tab[i], tab[i + 1]) < 0 && sort == 1)
			return (0);
		i++;
	}
	return (1);
}
