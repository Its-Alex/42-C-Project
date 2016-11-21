/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:31:45 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 15:44:50 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int		count_word;
	int		count_letter;

	count_word = 1;
	count_letter = 0;
	while (count_word < argc)
	{
		while (argv[count_word][count_letter] != '\0')
		{
			ft_putchar(argv[count_word][count_letter]);
			count_letter++;
		}
		ft_putchar('\n');
		count_letter = 0;
		count_word++;
	}
	return (0);
}
