/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_suffix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 21:15:45 by malexand          #+#    #+#             */
/*   Updated: 2015/07/25 22:08:42 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		if (root->left != 0)
			btree_apply_suffix(root->left, applyf);
		if (root->right != 0)
			btree_apply_suffix(root->right, applyf);
		applyf(root->item);
	}
}
