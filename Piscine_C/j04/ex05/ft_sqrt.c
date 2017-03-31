/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/13 17:01:57 by malexand          #+#    #+#             */
/*   Updated: 2015/07/14 21:28:44 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt(int nb)
{
	int racine;

	racine = 0;
	if (nb < 0)
		return (0);
	while ((racine * racine) < nb)
	{
		racine++;
	}
	if ((racine * racine) == nb)
		return (racine);
	return (0);
}
