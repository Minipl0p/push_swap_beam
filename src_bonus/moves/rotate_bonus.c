/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:28:31 by tonlogin          #+#    #+#             */
/*   Updated: 2026/01/02 12:51:20 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/Includes/libft.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || ft_lstsize(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra_bns(t_list **a)
{
	rotate(a);
}

void	rb_bns(t_list **b)
{
	rotate(b);
}

void	rr_bns(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
