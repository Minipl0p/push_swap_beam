/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 10:34:19 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/20 10:28:30 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

static int	*calc_dp(int *values, int size)
{
	int	*dp;
	int	i;
	int	j;

	dp = malloc(sizeof(int) * size);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dp[i] = 1;
		j = 0;
		while (j < i)
		{
			if (values[j] < values[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			j++;
		}
		i++;
	}
	return (dp);
}

static int	find_max_dp(int *dp, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (dp[i] > max)
			max = dp[i];
		i++;
	}
	return (max);
}

static void	mark_lis(t_list *lst, int *dp, int size, int max_len)
{
	int		i;
	int		current_len;
	t_list	*node;
	int		j;

	current_len = max_len;
	i = size - 1;
	while (i >= 0 && current_len > 0)
	{
		node = lst;
		j = 0;
		while (j < i)
		{
			node = node->next;
			j++;
		}
		if (dp[i] == current_len)
		{
			((t_content *)node->content)->is_lis = 1;
			current_len--;
		}
		i--;
	}
}

int	set_lis(t_list *lst)
{
	int	size;
	int	*values;
	int	*dp;
	int	max_len;

	size = ft_lstsize(lst);
	values = copy_values(lst, size);
	if (!values)
		return (0);
	dp = calc_dp(values, size);
	if (!dp)
	{
		free(values);
		return (0);
	}
	reset_is_lis(lst);
	max_len = find_max_dp(dp, size);
	mark_lis(lst, dp, size, max_len);
	free(values);
	free(dp);
	return (1);
}
