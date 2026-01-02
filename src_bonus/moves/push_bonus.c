/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:29:18 by tonlogin          #+#    #+#             */
/*   Updated: 2026/01/02 12:51:09 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/Includes/libft.h"

static void	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa_bns(t_list **a, t_list **b)
{
	push(b, a);
}

void	pb_bns(t_list **a, t_list **b)
{
	push(a, b);
}
