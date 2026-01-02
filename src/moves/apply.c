/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aply.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 13:55:29 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 08:31:06 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

static void	rotate_both(t_list **a, t_list **b, t_cost *m)
{
	while (m->cost_dest > 0 && m->cost_src > 0)
	{
		rr(a, b);
		m->cost_dest--;
		m->cost_src--;
	}
	while (m->cost_dest < 0 && m->cost_src < 0)
	{
		rrr(a, b);
		m->cost_dest++;
		m->cost_src++;
	}
}

static void	rotate_a(t_list **a, int *c)
{
	while (*c > 0)
	{
		ra(a);
		(*c)--;
	}
	while (*c < 0)
	{
		rra(a);
		(*c)++;
	}
}

static void	rotate_b(t_list **b, int *c)
{
	while (*c > 0)
	{
		rb(b);
		(*c)--;
	}
	while (*c < 0)
	{
		rrb(b);
		(*c)++;
	}
}

void	apply_best_move(t_list **a, t_list **b, t_cost m)
{
	rotate_both(a, b, &m);
	rotate_a(a, &m.cost_dest);
	rotate_b(b, &m.cost_src);
	pa(a, b);
}
