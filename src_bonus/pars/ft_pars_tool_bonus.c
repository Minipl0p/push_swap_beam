/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_tool_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniplop <miniplop@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:04:15 by miniplop          #+#    #+#             */
/*   Updated: 2026/01/02 10:27:56 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/ft_pushswap_bonus.h"

int	is_args_valid_bns(char **args)
{
	int	i;
	int	j;
	int	err;

	i = 1;
	while (args[i])
	{
		j = 0;
		err = 1;
		while (args[i][j])
		{
			if (args[i][j] != ' ')
				err = 0;
			j++;
		}
		if (err == 1 || j == 0)
			return (0);
		i++;
	}
	return (1);
}
