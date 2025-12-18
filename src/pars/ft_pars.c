/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 18:52:40 by pchazalm          #+#    #+#             */
/*   Updated: 2025/12/17 17:39:08 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../header/ft_pushswap.h"
#include <limits.h>

static int	ft_check_if_digit(char *join, int *i)
{
	while (ft_isdigit(join[*i]))
		(*i)++;
	if (join[*i] && join[*i] != ' ')
		return (0);
	return (1);
}

static int	ft_check_if_sign(char *join, int *i)
{
	int	start;

	(*i)++;
	start = *i;
	while (ft_isdigit(join[*i]))
		(*i)++;
	if (start == *i || (join[*i] && join[*i] != ' ' ))
		return (0);
	return (1);
}

static int	ft_check_all(char *join, int *i)
{
	int	err;

	if (join[*i] == '-' || join[*i] == '+')
	{
		err = ft_check_if_sign(join, i);
		if (err == 0)
			return (0);
	}
	else if (ft_isdigit(join[*i]))
	{
		err = ft_check_if_digit(join, i);
		if (err == 0)
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	ft_is_in_limits(char *join)
{
	int			i;
	long int	tmp;

	i = 0;
	while (join[i])
	{
		while (join[i] && join[i] == ' ')
			i++;
		tmp = ft_atol(join + i);
		if (tmp > INT_MAX || tmp < INT_MIN)
			return (0);
		while (join[i] && join[i] != ' ')
			i++;
	}
	return (1);
}

char	*ft_pars(int ac, char **av)
{
	char	*join;
	int		i;
	int		err;

	err = is_args_valid(av);
	join = ft_join_wish(ac, av);
	if (!join || !err)
		return (NULL);
	err = ft_is_in_limits(join);
	if (err == 0)
		return (NULL);
	i = 0;
	while (join[i])
	{
		ft_skip_space(join, &i);
		err = ft_check_all(join, &i);
		if (err == 0)
			return (NULL);
		ft_skip_space(join, &i);
	}
	return (join);
}
