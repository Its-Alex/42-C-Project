/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scrambler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 12:32:55 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 12:43:33 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_scrambler(int ***a, int *b, int *******c, int ****d)
{
	int tmp1;
	int tmp2;

	tmp1 = *******c;
	*******c = ***a;
	tmp2 = ****d;
	****d = tmp1;
	tmp1 = *b;
	*b = tmp2;
	***a = tmp1;
}