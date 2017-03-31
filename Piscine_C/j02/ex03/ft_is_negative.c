/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 09:52:55 by malexand          #+#    #+#             */
/*   Updated: 2015/07/21 12:52:05 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_is_negative(int nombre)
{
	if (nombre < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}
