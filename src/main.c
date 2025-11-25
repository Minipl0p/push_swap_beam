/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:37:57 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/25 15:54:15 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pushswap.h"

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

void	run_algo(t_stack *a, t_stack *b, int n, int d)
{

}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		check;

	if (ac < 2)
		return (1);
	stack_a = ft_do_lst(ac, av);
	if (!stack_a)
		return (1);
	ft_lstclear(&stack_a, free);
	ft_lstclear(&stack_b, free);
}
