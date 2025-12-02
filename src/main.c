/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:57 by pchazalm          #+#    #+#             */
/*   Updated: 2025/12/02 13:37:16 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pushswap.h"

static t_cost	find_best_cost(t_cost *c, int n)
{
	int		i;
	t_cost	best;

	best = c[0];
	i = 1;
	while (i < n)
	{
		if (c[i].total < best.total)
			best = c[i];
		i++;
	}
	return (best);
}

static void	final_rotate(t_list **a)
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

static t_list	*ft_do_lst(int ac, char **av)
{
	char	*str;
	t_list	*lst;

	str = ft_pars(ac, av);
	if (!str)
		return (NULL);
	lst = ft_init_lst(str);
	if (!ft_check_double(lst))
	{
		ft_puterror();
		return (NULL);
	}
	return (lst);
}

static int	apply_turk(t_list **a, t_list **b)
{
	int		size_b;
	t_cost	*costs;
	t_cost	best;

	while (*b)
	{
		size_b = ft_lstsize(*b);
		costs = malloc(sizeof(t_cost) * size_b);
		if (!costs)
			return (0);
		calc_costs(*a, *b, costs);
		best = find_best_cost(costs, size_b);
		apply_best_move(a, b, best);
		free(costs);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		err;

	if (ac < 2)
		return (0);
	a = ft_do_lst(ac, av);
	if (!a)
		return (1);
	set_lis(a);
	b = NULL;
	push_non_lis(&a, &b);
	err = apply_turk(&a, &b);
	if (!err)
	{
		ft_puterror();
		ft_lstclear(&a, free);
		ft_lstclear(&b, free);
		return (1);
	}
	final_rotate(&a);
	// print_stacks(a, b);
	ft_lstclear(&a, free);
	return (0);
}
