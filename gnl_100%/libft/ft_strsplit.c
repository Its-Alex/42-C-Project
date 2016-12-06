/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:34:21 by malexand          #+#    #+#             */
/*   Updated: 2016/11/12 12:54:53 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_count_word(const char *str, char c)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			word++;
		i++;
	}
	if (str[0] != '\0')
		word++;
	return (word);
}

static char		*ft_word(char const *s, char c)
{
	char	*tmp_w;
	int		size;
	int		i;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	if (!(tmp_w = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tmp_w[i] = s[i];
		i++;
	}
	tmp_w[i] = '\0';
	return (tmp_w);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		len;
	int		i;

	if (!s || !c)
		return (NULL);
	len = ft_count_word(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	i = -1;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			tab[++i] = ft_word(s, c);
		while (*s && *s != c)
			s++;
	}
	tab[++i] = NULL;
	return (tab);
}
