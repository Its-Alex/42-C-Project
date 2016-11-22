/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 22:13:07 by alex              #+#    #+#             */
/*   Updated: 2016/11/22 22:56:56 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		get_line(const int fd, int nb_line, char **line)
{
	int				count;
	char			*str;
	static	char	*save[SIZE_FD];

	if (save[fd] == NULL)
	{
		save[fd] = ft_strnew(sizeof(char));
		save[0] = '\0';
	}
	while (count < line && )
	{
		save[fd] = ft_strjoin_free(save[fd],
			get_next_line(fd, &str));
		count++;
	}
	return (0);
}