/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:25:42 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/17 13:34:19 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_list		*ft_lststr_sort(t_list *lst)
{
	char	*temp;
	t_list	*tmplst;
	t_list	*start;

	start = lst;
	tmplst = lst;
	if (!lst)
		return (lst);
	while (lst)
	{
		while (tmplst)
		{
			if (ft_strcmp(lst->content, tmplst->content) > 0)
			{
				temp = lst->content;
				lst->content = tmplst->content;
				tmplst->content = temp;
				ft_swap(&lst->content_size, &tmplst->content_size);
			}
			tmplst = tmplst->next;
		}
		lst = lst->next;
		tmplst = lst;
	}
	return (start);
}
