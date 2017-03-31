/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/22 18:53:12 by malexand          #+#    #+#             */
/*   Updated: 2015/07/22 18:53:13 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_params(int ac, char **av)
{
	t_list *list;
	t_list *tmp;
	t_list *first;

	first = NULL;
	list = NULL;
	if (ac != 0)
	{
		ac--;
		first = ft_create_elem(av[ac]);
		first->next = list;
		while (ac < 0)
		{
			ac--;
			tmp = ft_create_elem(av[ac]);
			list = tmp;
			list = list->next;
		}
	}
	return (first);
}
