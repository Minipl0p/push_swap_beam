/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 15:38:43 by tonlogin          #+#    #+#             */
/*   Updated: 2025/11/28 15:41:27 by tonlogin         ###   ########.fr       */
/*                     */
/* ************************************************************************** */

#include "../../header/ft_pushswap.h"

void	reset_is_lis(t_list *lst)
{
	int	medians[3];

	medians[0] = 0;
	get_medians(lst, medians);
	while (lst)
	{
		((t_content *)lst->content)->is_lis = 0;
		if (((t_content *)lst->content)->value <= medians[0])
			((t_content *)lst->content)->bucket = 0;
		else if (((t_content *)lst->content)->value <= medians[1])
			((t_content *)lst->content)->bucket = 1;
		else if (((t_content *)lst->content)->value <= medians[2])
			((t_content *)lst->content)->bucket = 2;
		else
			((t_content *)lst->content)->bucket = 3;
		lst = lst->next;
	}
}

int	*copy_values(t_list *lst, int size)
{
	int	*values;
	int	i;

	values = malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	i = 0;
	while (lst)
	{
		values[i] = ((t_content *)lst->content)->value;
		i++;
		lst = lst->next;
	}
	return (values);
}

static void	find_prev_lis(t_list *a, t_content **prev)
{
	int		i;
	int		j;
	t_list	*head;

	i = ft_lstsize(a);
	while (i > 1)
	{
		j = 0;
		head = a;
		while (j < i - 1)
		{
			head = head->next;
			j++;
		}
		if (((t_content *)head->content)->is_lis == 1)
		{
			*prev = (t_content *)head->content;
			break ;
		}
		i--;
	}
}

static void	find_prev_next_lis(t_list *a, t_content **prev, t_content **next)
{
	*prev = NULL;
	*next = NULL;
	while (a)
	{
		if (((t_content *)a->content)->is_lis == 1)
		{
			*next = (t_content *)a->content;
			break ;
		}
		a = a->next;
	}
	find_prev_lis(a, prev);
}

int	is_between_lis(t_list *a, t_content *elem)
{
	t_content	*prev;
	t_content	*next;
	int			x;

	if (!a || !elem)
		return (0);
	x = elem->value;
	find_prev_next_lis(a, &prev, &next);
	return (prev->value < x && x < next->value);
}
