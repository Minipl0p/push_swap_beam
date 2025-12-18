/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:55 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/18 13:00:25 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	find_min(t_list *a)
{
	int			m;
	t_content	*c;

	c = (t_content *)a->content;
	m = c->value;
	a = a->next;
	while (a)
	{
		c = (t_content *)a->content;
		if (c->value < m)
			m = c->value;
		a = a->next;
	}
	return (m);
}

int	rotation_cost(int i, int size)
{
	if (i <= size / 2)
		return (i);
	return ((i - size));
}

void	final_rotate(t_list **a)
{
	int	i;
	int	size;

	i = index_of(*a, find_min(*a));
	size = ft_lstsize(*a);
	if (i <= size / 2)
		while (i-- > 0)
			ra(a);
	else
		while (i++ < size)
			rra(a);
}
