/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:39:24 by malexand          #+#    #+#             */
/*   Updated: 2016/11/04 13:40:21 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		count_nb_array;
	int		count_true;

	count_nb_array = 0;
	count_true = 0;
	while (tab[count_nb_array])
	{
		if (f(tab[count_nb_array]) == 1)
			count_true++;
		count_nb_array++;
	}
	return (count_true);
}
