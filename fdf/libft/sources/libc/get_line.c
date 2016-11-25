/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:13:07 by alex              #+#    #+#             */
/*   Updated: 2016/11/23 10:47:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		get_line(const int fd, int nb_line, char **line)
{
	int				count;
	char			*str;
	static	char	*save[SIZE_FD];

	count = 0;
	if (save[fd] == NULL)
	{
		save[fd] = ft_strnew(sizeof(char));
		save[fd][0] = '\0';
	}
	while (count < nb_line)
	{
		get_next_line(fd, &str);
		save[fd] = ft_strjoin_free(save[fd], str);
		count++;
	}
	*line[0] = '\0';
	return (0);
}
