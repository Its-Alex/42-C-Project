/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 21:04:03 by malexand          #+#    #+#             */
/*   Updated: 2015/07/25 22:08:20 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		if (root->letf != 0)
			btree_apply_infix(root->left, applyf);
		applyf(root->item);
		if (root->right != 0)
			btree_apply_infix(root->right, applyf);
	}
}
