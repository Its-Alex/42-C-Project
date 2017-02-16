/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:55:12 by malexand          #+#    #+#             */
/*   Updated: 2017/02/16 11:19:34 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

int		main(int argc, const char **argv)
{
	int		count;
	int		fd;
	int		ret;
	char	*str;
	char	*tmp;

	count = 1;
	if (argc > 1)
	{
		str = (char*)malloc(sizeof(char));
		str[0] = '\0';
		while (argv[count])
		{
			ft_bzero(str, ft_strlen(str));
			fd = 0;
			ret = 0;
			if ((fd = open(argv[count], O_RDONLY)) < 0)
				error(1, 1, "");
			while ((ret = get_next_line(fd, &tmp)) == 1)
			{
				str = ft_strjoin_free(str, tmp);
				str = ft_strjoin_free(str, "\n");
				ft_strdel(&tmp);
			}
			if (ret == -1)
				error(1, 1, "");
			if (str[0] == '\0')
				error(1, 0, "Map empty!");
			if (close(fd) < 0)
				error(1, 1, "");
			ft_putstr(str);
			count++;
		}
	}
	return (0);
}
