/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 10:43:03 by root              #+#    #+#             */
/*   Updated: 2016/11/22 15:47:34 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *alst;
	while (lst)
	{
		tmp = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmp;
	}
	*alst = NULL;
}
