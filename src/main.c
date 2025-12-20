/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:57 by pchazalm          #+#    #+#             */
/*   Updated: 2025/12/18 18:53:58 by miniplop         ###   ########.fr       */
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

static t_list	*ft_do_lst(int ac, char **av)
{
	char	*str;
	t_list	*lst;

	str = ft_pars(ac, av);
	if (!str)
	{
		ft_puterror();
		return (NULL);
	}
	lst = ft_init_lst(str);
	if (!ft_check_double(lst))
	{
		ft_puterror();
		ft_lstclear(&lst, free);
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

static int	mega_sort(t_list **a, t_list **b)
{
	static int	err = 1;

	err = set_lis(*a);
	if (!err)
	{
		ft_lstclear(a, free);
		ft_lstclear(b, free);
		return (1);
	}
	push_non_lis(a, b);
	err = apply_turk(a, b);
	if (!err)
	{
		ft_lstclear(a, free);
		ft_lstclear(b, free);
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_list		*a;
	t_list		*b;
	static int	err = 0;

	if (ac < 2)
		return (1);
	a = ft_do_lst(ac, av);
	if (!a)
		return (1);
	b = NULL;
	if (ft_lstsize(a) <= 5)
	{
		mini_sort(&a, &b);
		return (0);
	}
	err = mega_sort(&a, &b);
	if (err)
		return (1);
	final_rotate(&a);
	ft_lstclear(&a, free);
	return (0);
}
