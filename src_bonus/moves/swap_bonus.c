/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:29:52 by tonlogin          #+#    #+#             */
/*   Updated: 2026/01/02 12:51:45 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/Includes/libft.h"

static void	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	void	*tmp;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	sa_bns(t_list **a)
{
	swap(a);
}

void	sb_bns(t_list **b)
{
	swap(b);
}

void	ss_bns(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
