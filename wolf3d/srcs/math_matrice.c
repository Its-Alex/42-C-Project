/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_matrice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 13:09:56 by malexand          #+#    #+#             */
/*   Updated: 2017/02/14 16:33:32 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		rotate(double *x, double *y, double coef)
{
	double		tmp;

	if (x == NULL || y == NULL)
		return ;
	tmp = *x;
	*x = *x * cos(coef) - *y * sin(coef);
	*y = tmp * sin(coef) + *y * cos(coef);
}
