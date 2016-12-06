/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 16:18:21 by malexand          #+#    #+#             */
/*   Updated: 2016/08/28 16:20:03 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*lstnew;
	t_list	*ret;

	lstnew = NULL;
	while (lst)
	{
		temp = f(lst);
		if (!lstnew)
		{
			lstnew = temp;
			ret = lstnew;
			lstnew->next = NULL;
		}
		else
		{
			lstnew->next = temp;
			temp->next = NULL;
			lstnew = lstnew->next;
		}
		lst = lst->next;
	}
	return (ret);
}
