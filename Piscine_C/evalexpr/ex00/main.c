/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/20 17:42:25 by malexand          #+#    #+#             */
/*   Updated: 2015/07/20 20:23:47 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_fonction.h"

int		ft_scan(char *src)
{
	int size;
	int nb_bracket;

	size = ft_strlen(src);
	nb_bracket = 0;
	while (src[i] != '\0' && size > 0)
	{
		if (src[i] == 40 || src[i] == 41)
			nb_bracket++;
		i++;
	}
	return (nb_bracket);
}

int 	ft_find_bracket(char *src)
{
	int size;

	size = ft_strlen(src);
	while 
}

int		eval_expr(char *str)
{

}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	else
	{
		eval_expr(*argv[1]);
	}
}
