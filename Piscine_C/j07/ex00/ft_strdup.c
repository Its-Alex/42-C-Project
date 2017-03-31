/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 10:51:55 by malexand          #+#    #+#             */
/*   Updated: 2015/07/20 19:23:40 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*p;
	int		size;

	if (src[i] == '\0')
		return (p = 0);
	while (src[size] != '\0')
		size++;
	i = 0;
	p = (char *)(malloc(sizeof(char) * size));
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	return (p);
}

int main (int argc, char **argv)
{
	int *p;
	char t = "Salut";

	p = ft_strdup(t);

	ft_putstr(p);
}
