/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:29:52 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 13:02:47 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

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

void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
