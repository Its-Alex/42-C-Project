/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unmatch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 13:13:04 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 14:35:57 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_unmatch(int *tab, int lenght)
{
	int i;
	int tmp;

	i = 0;
	while (tab[i] != '\0')
	{
		tab[i] = tmp;
		while (tab[i] != tab[k] && tab[k] != '\0')
			k++;
		if (tab[i] != tab[k])
			return (tab[i]);
		i++;
	}
	return (0);
}
