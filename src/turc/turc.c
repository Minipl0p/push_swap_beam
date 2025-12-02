/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 19:42:39 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 13:36:33 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

static int	find_score(int ra, int rb, int rra, int rrb)
{
	int	best;

	best = ft_max(ra, rb);
	if (ft_max(rra, rrb) < best)
		best = ft_max(rra, rrb);
	if (ra + rrb < best)
		best = ra + rrb;
	if (rra + rb < best)
		best = rra + rb;
	return (best);
}

static int	best_cost(int cost_dst, int cost_src, int len_dst, int len_src)
{
	int	r_dst;
	int	rr_dst;
	int	rs_src;
	int	rrs_src;

	r_dst = len_dst + cost_dst;
	rr_dst = -cost_dst;
	rs_src = len_src + cost_src;
	rrs_src = -cost_src;
	if (cost_dst >= 0)
	{
		r_dst = cost_dst;
		rr_dst = len_dst - cost_dst;
	}
	if (cost_src >= 0)
	{
		rs_src = cost_src;
		rrs_src = len_src - cost_src;
	}
	return (find_score(r_dst, rs_src, rr_dst, rrs_src));
}

int	index_of(t_list *lst, int value)
{
	int			i;
	t_content	*c;

	i = 0;
	while (lst)
	{
		c = (t_content *)lst->content;
		if (c->value == value)
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

static int	find_insert_index(t_list *lst, int x)
{
	int		i;
	int		v1;
	int		v2;
	t_list	*cur;

	cur = lst;
	i = 0;
	while (cur->next)
	{
		v1 = ((t_content *)cur->content)->value;
		v2 = ((t_content *)cur->next->content)->value;
		if ((x > v1 && x < v2)
			|| (v1 > v2 && (x > v1 || x < v2)))
			return (i + 1);
		cur = cur->next;
		i++;
	}
	return (0);
}

void	calc_costs(t_list *dest, t_list *src, t_cost *c)
{
	int	l_dest;
	int	l_src;
	int	i;
	int	x;

	l_dest = ft_lstsize(dest);
	l_src = ft_lstsize(src);
	i = 0;
	while (src)
	{
		x = ((t_content *)src->content)->value;
		c[i].index_src = i;
		c[i].index_dest = find_insert_index(dest, x);
		c[i].cost_src = rotation_cost(i, l_src);
		c[i].cost_dest = rotation_cost(c[i].index_dest, l_dest);
		c[i].total = best_cost(c[i].cost_dest, c[i].cost_src, l_dest, l_src);
		src = src->next;
		i++;
	}
}
