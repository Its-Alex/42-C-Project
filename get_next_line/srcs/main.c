/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:55:12 by malexand          #+#    #+#             */
/*   Updated: 2016/11/18 17:33:58 by malexand         ###   ########.fr       */
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

	// char *line;
	// int fd;
	// int fd2;
	// int fd3;
	// int	diff_file_size;
    
 	// system("mkdir -p sandbox");
	// system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	// system("echo '\n' >> sandbox/one_big_fat_line.txt");

	// fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	// fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC, 0755);

	// while (get_next_line(fd, &line) == 1)
	// {
	//     write(fd2, line, strlen(line));
	//     write(fd2, "\n", 1);
	// }
	// if (line)
	// 	write(fd2, line, strlen(line));
	// close(fd);
	// close(fd2);

	// system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	// fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	// diff_file_size = read(fd3, NULL, 10);
	// close(fd3);

	// if (diff_file_size == 0)
	//	printf("TRUE\n");
	return (0);
}
