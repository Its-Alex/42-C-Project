/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab2d_int_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 16:43:00 by malexand          #+#    #+#             */
/*   Updated: 2016/11/28 17:02:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		tab2d_int_malloc(t_tab2d *tab2d)
{
	int			count;
	int			*tab;

	count = 0;
	if ((tab2d->tab = (int**)malloc(sizeof(int) * tab2d->line)) == NULL)
		return (-1);
	if ((tab = (int*)malloc(sizeof(int) * tab2d->line * tab2d->column)) == NULL)
		return (-1);
	while (count < tab2d->line)
	{
		tab2d->tab[count] = &tab[count * tab2d->column];
		count++;
	}
	return (1);
}
