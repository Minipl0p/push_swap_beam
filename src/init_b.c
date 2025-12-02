/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:37:57 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 13:15:56 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pushswap.h"

int	lstsize_nonx(t_list *a, int x)
{
	int	count;

	if (!a)
		return (0);
	count = 0;
	if (x == -1)
	{
		while (a)
		{
			if (((t_content *)a->content)->is_lis == 0)
				count++;
			a = a->next;
		}
	}
	else
	{
		while (a)
		{
			if (((t_content *)a->content)->bucket == x
				&& ((t_content *)a->content)->is_lis == 0)
				count++;
			a = a->next;
		}
	}
	return (count);
}

static void	copy_to_array(t_list *a, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = ((t_content *)a->content)->value;
		a = a->next;
		i++;
	}
}

static void	simple_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	get_medians(t_list *a, int *med)
{
	int		size;
	int		*arr;

	size = ft_lstsize(a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	copy_to_array(a, arr, size);
	simple_sort(arr, size);
	med[0] = arr[size / 4];
	med[1] = arr[(size * 2) / 4];
	med[2] = arr[(size * 3) / 4];
	free(arr);
}

void	push_non_lis(t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (lstsize_nonx(*a, -1) > 0)
	{
		while (lstsize_nonx(*a, i) > 0)
		{
			if (((t_content *)(*a)->content)->bucket == i
				&& ((t_content *)(*a)->content)->is_lis == 0)
			{
				pb(a, b);
			}
			else
				ra(a);
		}
		i++;
	}
}
