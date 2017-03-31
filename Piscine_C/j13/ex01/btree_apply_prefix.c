/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malexand <malexand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/25 11:55:41 by malexand          #+#    #+#             */
/*   Updated: 2015/07/25 22:07:52 by malexand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		applyf(root->item);
		if (root->left != 0)
			btree_apply_prefix(root->left, applyf);
		if (root->right != 0)
			btree_apply_prefix(root->right, applyf);
	}
}
