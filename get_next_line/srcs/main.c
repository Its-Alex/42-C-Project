/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:55:12 by malexand          #+#    #+#             */
/*   Updated: 2016/11/18 15:52:56 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

int		main(int argc, const char **argv)
{
	char	*text;
	int		count;

	count = 0;
	text = ft_memalloc(400000);
	if (argv[0] == NULL && argc > 0)
		ft_putendl("Salut");
	if (get_next_line(422, &text) == -1)
		ft_putendl("TRUE\n");
	else
		ft_putendl("FALSE\n");
	return (0);
}
