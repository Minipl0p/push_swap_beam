/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:45:55 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 13:36:19 by tonlogin         ###   ########.fr       */
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
