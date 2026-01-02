/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:08:15 by pchazalm          #+#    #+#             */
/*   Updated: 2026/01/02 10:31:10 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap_bonus.h"

void	ft_free_clear_bns(t_list *lst, t_content *content)
{
	free(content);
	ft_lstclear(&lst, free);
}

void	ft_skip_space_bns(char *join, int *i)
{
	while (join[*i] == ' ')
		(*i)++;
}

char	*ft_skip_char_bns(char *str, char c, int in_out)
{
	char	*tmp;

	tmp = str;
	if (in_out == 0)
	{
		while (*tmp && *tmp == c)
			tmp++;
	}
	else
	{
		while (*tmp && *tmp != c)
			tmp++;
	}
	return (tmp);
}

int	ft_check_double_bns(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		lst = tmp->next;
		while (lst)
		{
			if (*(int *)tmp->content == *(int *)lst->content)
				return (0);
			lst = lst->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

t_list	*ft_init_lst_bns(char *str)
{
	static t_list	*lst = NULL;
	t_content		*content;
	t_list			*elem;

	while (*str && *(ft_skip_char_bns(str, ' ', 0)) != '\0')
	{
		str = ft_skip_char_bns(str, ' ', 0);
		content = malloc(sizeof(t_content));
		if (!content)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		content->value = ft_atoi(str);
		content->is_lis = 0;
		str = ft_skip_char_bns(str, ' ', 1);
		elem = ft_lstnew(content);
		if (!elem)
		{
			ft_free_clear_bns(lst, content);
			return (NULL);
		}
		ft_lstadd_back(&lst, elem);
	}
	return (lst);
}
