/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_postfix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 09:47:46 by pchazalm          #+#    #+#             */
/*   Updated: 2025/12/31 10:26:58 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/ft_btree.h"

void	btree_postfix(t_btree *root, void (*f)(void *))
{
	if (!root || !f)
		return ;
	btree_postfix(root->left, f);
	btree_postfix(root->left, f);
	f(root->content);
}
