/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 17:34:57 by malexand          #+#    #+#             */
/*   Updated: 2015/07/16 12:44:37 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		main(int argc, char **argv)
{
	int k;
	int i;

	k = 0;
	i = argc - 1;
	while (i > 0)
	{
		while (argv[i][k] != '\0')
		{
			ft_putchar(argv[i][k]);
			k++;
		}
		ft_putchar('\n');
		i--;
		k = 0;
	}
	return (0);
}
