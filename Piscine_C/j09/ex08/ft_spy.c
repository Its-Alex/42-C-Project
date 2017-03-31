/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 09:10:20 by malexand          #+#    #+#             */
/*   Updated: 2015/07/17 14:39:30 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 

int		main(int argc, char **argv)
{
	int 	i;
	int 	k;
	int 	j;
	char	mot1[] = "attack";
	char	mot2[] = "powers";
	char	mot3[] = "president";

	i = 1;
	j = 0;
	k = 0;
	while (i < argc)
	{
		while (argv[i][k] != '\0')
		{
			if (argv[i][k] >= 'A' && argv[i][k] <= 'Z')
				argv[i][k] += 32;
			k++;
		}
		k = 0;
		while (argv[i][k] < 'a' && argv[i][k] > 'z')
			k++;
		while (argv[i][k] != mot1[j] || argv[i][k] != mot2[j] || argv[i][k] != mot3[j])
			k++;
		while (argv[i][k + j] == mot1[j] || argv[i][k + j] == mot2[j] || argv[i][k + j] == mot3[j])
		{
			j++;
		}
		if (mot1[j] == '\0' || mot2[j] == '\0' || mot3[j] == '\0')
			write(1, "Alert!!!\n", 9);
		j = 0;
		i++;
	}
}
