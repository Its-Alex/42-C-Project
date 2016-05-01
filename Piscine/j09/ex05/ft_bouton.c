/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bouton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 22:59:11 by malexand          #+#    #+#             */
/*   Updated: 2015/07/16 23:23:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb);

int		ft_bouton(int i, int j, int k)
{
	if ((i < j && i > k) || (i < k && i > j))
		return (i);
	else if ((j < i && j > k) || (j > i && j < k))
		return (j);
	else if ((k < i && k > j) || (k > i && k < j))
		return (k);
	return (0);
}
