/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 11:36:11 by root              #+#    #+#             */
/*   Updated: 2016/11/22 15:47:34 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!alst)
		new->next = NULL;
	else
		new->next = *alst;
	*alst = new;
}
