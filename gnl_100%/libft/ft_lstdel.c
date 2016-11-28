/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacrozet <vacrozet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 16:03:20 by vacrozet          #+#    #+#             */
/*   Updated: 2016/08/28 16:09:41 by vacrozet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *delist;
	t_list *new_list;

	delist = *alst;
	while (delist)
	{
		new_list = delist->next;
		del(delist->content, delist->content_size);
		free(delist);
		delist = new_list;
	}
	*alst = NULL;
}
