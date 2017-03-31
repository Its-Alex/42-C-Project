/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/23 13:35:57 by malexand          #+#    #+#             */
/*   Updated: 2015/07/23 13:35:59 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *tmp;
	t_list *tmp_back;

	tmp = *begin_list->next;
	while (tmp->next != NULL)
	{
		tmp_back = tmp;
		tmp = tmp->next;
		tmp_back = tmp;
	}
	*begin_list->next = tmp_back;
}
