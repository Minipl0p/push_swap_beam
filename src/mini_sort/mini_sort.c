/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 18:30:12 by miniplop          #+#    #+#             */
/*   Updated: 2026/01/02 12:35:52 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

static void	two_sort(t_list **a)
{
	if (((t_content *)(*a)->content)->value
		> ((t_content *)(*a)->next->content)->value)
		ra(a);
}

static void	three_sort(t_list **a)
{
	int	max;

	max = get_max(*a);
	if (max == 0)
		ra(a);
	else if (max == 1)
		rra(a);
	if (((t_content *)(*a)->content)->value
		> ((t_content *)(*a)->next->content)->value)
		sa(a);
}

static void	four_sort(t_list **a, t_list **b)
{
	min_to_top(a, 4);
	pb(a, b);
	three_sort(a);
	pa(a, b);
}

static void	five_sort(t_list **a, t_list **b)
{
	min_to_top(a, 5);
	pb(a, b);
	min_to_top(a, 4);
	pb(a, b);
	three_sort(a);
	pa(a, b);
	pa(a, b);
}

void	mini_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (is_sorted(*a))
	{
		ft_lstclear(a, free);
		return ;
	}
	else if (size <= 2)
		two_sort(a);
	else if (size <= 3)
		three_sort(a);
	else if (size <= 4)
		four_sort(a, b);
	else if (size <= 5)
		five_sort(a, b);
	ft_lstclear(a, free);
}
