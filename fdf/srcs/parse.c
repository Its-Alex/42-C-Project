/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:21:24 by malexand          #+#    #+#             */
/*   Updated: 2016/11/23 18:13:44 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/fdf.h"




char	*parse_file(const char *file_name)
{
	int		fd;
	int		ret;
	//char	**str;

	ret = 1;
	fd = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
	{
		ft_putstr_color("Error \x1B[0m: ", RED);
		perror("");
	}
	while (ret == 1)
	{
		//ret = get_next_line(fd, str[])
	}
	return ("");
}
