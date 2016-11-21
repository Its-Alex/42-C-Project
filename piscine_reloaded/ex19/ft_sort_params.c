/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 17:48:13 by malexand          #+#    #+#             */
/*   Updated: 2016/11/03 17:49:56 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_params(char **argv, int argc)
{
	char	*tmp;
	int		find;
	int		count;

	find = 1;
	count = 0;
	while (find)
	{
		find = 0;
		count = 0;
		while (++count < argc - 1)
		{
			if (ft_strcmp(argv[count], argv[count + 1]) > 0)
			{
				tmp = argv[count];
				argv[count] = argv[count + 1];
				argv[count + 1] = tmp;
				find = 1;
			}
		}
	}
}

int		main(int argc, char **argv)
{
	int		count;

	count = 0;
	ft_sort_params(argv, argc);
	while (++count < argc)
	{
		ft_putstr(argv[count]);
		ft_putchar('\n');
	}
	return (0);
}
