/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 14:15:40 by malexand          #+#    #+#             */
/*   Updated: 2015/07/20 14:20:54 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H

char **ft_split_whitespaces(char *str);
typedef struct	s_stock_par
{
	int		size_paran;
	char	*str;
	char	*copy;
	char	**tab;
}				t_stock_par;

#endif
