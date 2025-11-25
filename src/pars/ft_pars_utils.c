/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:08:15 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/14 12:27:33 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "../header/push_swap.h"

void	ft_free_clear(t_list *lst, t_content *content)
{
	free(content);
	ft_lstclear(&lst, free);
}

void	ft_skip_space(char *join, int *i)
{
	while (join[*i] == ' ')
		(*i)++;
}

char	*ft_skip_char(char *str, char c, int in_out)
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

int	ft_check_double(t_list *lst)
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

t_list	*ft_init_lst(char *str)
{
	t_list		*lst;
	t_content	*content;
	t_list		*elem;

	lst = NULL;
	while (*str && *(ft_skip_char(str, ' ', 0)) != '\0')
	{
		str = ft_skip_char(str, ' ', 0);
		content = malloc(sizeof(t_content));
		if (!content)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		content->value = ft_atoi(str);
		str = ft_skip_char(str, ' ', 1);
		elem = ft_lstnew(content);
		if (!elem)
		{
			ft_free_clear(lst, content);
			return (NULL);
		}
		ft_lstadd_back(&lst, elem);
	}
	return (lst);
}
