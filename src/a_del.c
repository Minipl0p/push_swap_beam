/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tonlogin <tonlogin@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 07:52:33 by tonlogin          #+#    #+#             */
/*   Updated: 2025/12/02 10:14:54 by tonlogin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_pushswap.h"

void	print_stacks(t_list *a, t_list *b)
{
	t_list	*tmpa;
	t_list	*tmpb;
	t_content *ca;
	t_content *cb;

	tmpa = a;
	tmpb = b;

	ft_printf("\n======== STACKS ========\n");
	ft_printf("     A       |        B\n");
	ft_printf("-----------------------\n");

	while (tmpa || tmpb)
	{
		if (tmpa)
			ca = (t_content *)tmpa->content;
		else
			ca = NULL;

		if (tmpb)
			cb = (t_content *)tmpb->content;
		else
			cb = NULL;

		// Print A side
		if (ca)
			ft_printf(" %d (%d)[%d]   ", ca->value, ca->is_lis, ca->bucket);
		else
			ft_printf("        ");

		ft_printf(" | ");

		// Print B side
		if (cb)
			ft_printf(" %d (%d)[%d]", cb->value, cb->is_lis, cb->bucket);
		else
			ft_printf("       ");

		ft_printf("\n");

		if (tmpa)
			tmpa = tmpa->next;
		if (tmpb)
			tmpb = tmpb->next;
	}

	ft_printf("-----------------------------------------\n\n");
}

