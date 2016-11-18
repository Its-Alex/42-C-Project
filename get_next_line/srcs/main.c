/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:55:12 by malexand          #+#    #+#             */
/*   Updated: 2016/11/18 17:25:08 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/get_next_line.h"

int		main(int argc, const char **argv)
{
	// char	*text;
	// int		count;
	// int		fd;

	// count = 0;
	// text = ft_memalloc(400000);
	// fd = open(argv[1], O_RDONLY);
	if (argv[0] == NULL && argc > 0)
	 	ft_putendl("Salut");
	// while (get_next_line(fd, &text) > 0)
	// 	ft_putendl(text);
	// close(fd);
	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	if (strcmp(line, str) == 0)
		printf("TRUE\n");
	return (0);
}
