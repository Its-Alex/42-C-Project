/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_array_3d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:00:05 by malexand          #+#    #+#             */
/*   Updated: 2017/03/31 17:57:32 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

char				***parse_array_3d(char *str, char carac1, char carac2)
{
	int		len;
	int		count;
	char	**split;
	char	***parse;

	len = 0;
	count = 0;
	split = ft_strsplit(str, carac1);
	while (split[len])
		len++;
	parse = (char ***)ft_memalloc(sizeof(*parse) * (len + 1));
	while (count < len)
	{
		parse[count] = ft_strsplit(split[count], carac2);
		ft_strdel(&split[count]);
		count++;
	}
	parse[count] = NULL;
	free(split);
	return (parse);
}
