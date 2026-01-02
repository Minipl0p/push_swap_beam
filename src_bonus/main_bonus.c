/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:57 by pchazalm          #+#    #+#             */
/*   Updated: 2026/01/02 13:18:57 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pushswap_bonus.h"

static int	apply_order(char *order, t_list **a, t_list **b)
{
	if (!order)
		return (-1);
	if (!ft_strcmp(order, "pa\n"))
		pa_bns(a, b);
	else if (!ft_strcmp(order, "pb\n"))
		pb_bns(a, b);
	else if (!ft_strcmp(order, "ra\n"))
		ra_bns(a);
	else if (!ft_strcmp(order, "rb\n"))
		rb_bns(a);
	else if (!ft_strcmp(order, "rr\n"))
		rr_bns(a, b);
	else if (!ft_strcmp(order, "rra\n"))
		rra_bns(a);
	else if (!ft_strcmp(order, "rrb\n"))
		rrb_bns(a);
	else if (!ft_strcmp(order, "rrr\n"))
		rrr_bns(a, b);
	else if (!ft_strcmp(order, "sa\n"))
		sa_bns(a);
	else if (!ft_strcmp(order, "sb\n"))
		sb_bns(a);
	else if (!ft_strcmp(order, "ss\n"))
		ss_bns(a, b);
	return (1);
}

static int	is_sorted_bns(t_list *a)
{
	while (a->next)
	{
		if (((t_content *)a->content)->value
			> ((t_content *)a->next->content)->value)
			return (0);
		a = a->next;
	}
	return (1);
}

static t_list	*ft_do_lst(int ac, char **av)
{
	char	*str;
	t_list	*lst;

	str = ft_pars_bns(ac, av);
	if (!str)
	{
		ft_puterror();
		return (NULL);
	}
	lst = ft_init_lst_bns(str);
	if (!ft_check_double_bns(lst))
	{
		ft_puterror();
		ft_lstclear(&lst, free);
		return (NULL);
	}
	return (lst);
}

static int	read_term(t_list **a, t_list **b)
{
	char	*order;
	int		check;

	while (1)
	{
		order = get_next_line(0);
		if (!order)
			return (1);
		check = apply_order(order, a, b);
		free(order);
		if (check == -1)
		{
			ft_puterror();
			break ;
		}
	}
	return (-1);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		check;

	if (ac < 2)
		return (1);
	a = ft_do_lst(ac, av);
	if (!a)
		return (1);
	b = NULL;
	check = read_term(&a, &b);
	if (check == 1 && is_sorted_bns(a))
		write(1, "OK\n", 3);
	else if (check == 1)
		write(1, "KO\n", 3);
	if (b)
		ft_lstclear(&b, free);
	ft_lstclear(&a, free);
	return (0);
}
