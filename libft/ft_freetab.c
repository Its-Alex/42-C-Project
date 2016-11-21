/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:45:12 by malexand          #+#    #+#             */
/*   Updated: 2016/11/21 18:31:10 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = ft_strlen(tab[0]);
	if (tab == NULL)
	{
		ft_strdel(tab);
		tab = NULL;
		return ;
	}
	while (i >= 0)
	{
		ft_strdel(&tab[i]);
		tab[i] = NULL;
		i--;
	}
	ft_strdel(tab);
	tab = NULL;
}
