/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:12:59 by miniplop          #+#    #+#             */
/*   Updated: 2025/12/18 12:46:34 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"
#include "../../libft/libft.h"

int	get_max(t_list *a)
{
	int	i;
	int	i_max;
	int	max;

	i = 0;
	i_max = 0;
	max = ((t_content *)a->content)->value;
	while (a->next)
	{
		if (max < ((t_content *)a->next->content)->value)
		{
			i_max = i + 1;
			max = ((t_content *)a->next->content)->value;
		}
		i++;
		a = a->next;
	}
	return (i_max);
}

static int	find_min_idx(t_list *a)
{
	int			m;
	int			i;
	int			i_max;
	t_content	*c;

	i = 0;
	i_max = 0;
	c = (t_content *)a->content;
	m = c->value;
	a = a->next;
	while (a)
	{
		c = (t_content *)a->content;
		if (c->value < m)
		{
			m = c->value;
			i_max = i + 1;
		}
		a = a->next;
		i++;
	}
	return (i_max);
}

static void	double_rot(t_list **a, int rot)
{
	if (rot == 0)
	{
		ra(a);
		ra(a);
	}
	else
	{
		rra(a);
		rra(a);
	}
}

void	min_to_top(t_list **a, int len)
{
	int	pos;

	pos = find_min_idx(*a);
	if (len == 4)
	{
		if (pos == 1)
			ra(a);
		else if (pos == 2)
			double_rot(a, 0);
		else if (pos == 3)
			rra(a);
	}
	else if (len == 5)
	{
		if (pos == 1)
			ra(a);
		else if (pos == 2)
			double_rot(a, 0);
		else if (pos == 3)
			double_rot(a, 1);
		else if (pos == 4)
			rra(a);
	}
}
