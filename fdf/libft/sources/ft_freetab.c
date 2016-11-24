/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:45:12 by malexand          #+#    #+#             */
/*   Updated: 2016/11/24 16:49:19 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_freetab(char **tab)
{
	int	count;

	count = 0;
	if (tab == NULL)
	{
		free(tab);
		tab = NULL;
		return ;
	}
	while (tab[count])
	{
		ft_strdel(&tab[count]);
		tab[count] = NULL;
		count++;
	}
	ft_strdel(&tab[count]);
	tab[count] = NULL;
	free(tab);
	tab = NULL;
}
