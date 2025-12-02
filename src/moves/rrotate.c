/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:24:27 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 13:01:59 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

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

void	rra(t_list **a)
{
	rrotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rrotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
}
