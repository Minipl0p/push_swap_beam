/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:24:27 by tonlogin          #+#    #+#             */
/*   Updated: 2026/01/02 12:51:35 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/Includes/libft.h"

static void	rrotate(t_list **stack)
{
	t_list	*prev;
	t_list	*last;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra_bns(t_list **a)
{
	rrotate(a);
}

void	rrb_bns(t_list **b)
{
	rrotate(b);
}

void	rrr_bns(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
}
