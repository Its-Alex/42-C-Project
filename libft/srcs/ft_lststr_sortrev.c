/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststr_sortrev.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skyzie <skyzie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 00:27:46 by skyzie            #+#    #+#             */
/*   Updated: 2017/01/17 00:28:13 by skyzie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/libft.h"

t_list		*ft_lststr_sortrev(t_list *lst)
{
	char	*temp;
	t_list	*tmplst;
	t_list	*start;

	start = lst;
	tmplst = lst;
	if (!lst)
		return (lst);
	temp = lst->content;
	while (lst)
	{
		while (tmplst)
		{
			if (ft_strcmp(lst->content, tmplst->content) < 0)
			{
				temp = lst->content;
				lst->content = tmplst->content;
				tmplst->content = temp;
			}
			tmplst = tmplst->next;
		}
		lst = lst->next;
		tmplst = lst;
	}
	return (start);
}