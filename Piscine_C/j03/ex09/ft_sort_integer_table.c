/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 21:13:34 by malexand          #+#    #+#             */
/*   Updated: 2015/07/11 21:52:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_sort_integer_table(int tab*, int size)
{
	int tab_sort[size];
	int tmp;
	int i;
	int cmpt;

	tmp = 0;
	i = 0;
	cmpt = 0;
	while (tab_sort[size] != tab[size])
	{
		if (tmp == 0)
		{	
			while (cmpt < size)
			{
				if (tab[cmpt] > tmp)
					tmp = tab[i];
				cmpt++;
			}
		}
		if (tab[i] 
		tab_sort[i] = tmp;
		if 
	}
}
