/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:25:23 by pchazalm          #+#    #+#             */
/*   Updated: 2026/01/02 10:39:34 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_BONUS_H
# define FT_PUSHSWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "../libft/Includes/libft.h"

typedef struct s_content
{
	int	value;
	int	is_lis;
	int	bucket;
}				t_content;

typedef struct s_cost
{
	int	index_src;
	int	index_dest;
	int	cost_dest;
	int	cost_src;
	int	total;
}				t_cost;

//Pars
char	*ft_pars_bns(int ac, char **av);
int		is_args_valid_bns(char **args);
void	ft_free_clear_bns(t_list *lst, t_content *content);
void	ft_skip_space_bns(char *join, int *i);
char	*ft_skip_char_bns(char *str, char c, int in_out);
int		ft_check_double_bns(t_list *lst);
t_list	*ft_init_lst_bns(char *str);

//moves
void	pa_bns(t_list **a, t_list **b);
void	pb_bns(t_list **a, t_list **b);
void	sa_bns(t_list **a);
void	sb_bns(t_list **b);
void	ss_bns(t_list **a, t_list **b);
void	ra_bns(t_list **a);
void	rb_bns(t_list **b);
void	rr_bns(t_list **a, t_list **b);
void	rra_bns(t_list **a);
void	rrb_bns(t_list **b);
void	rrr_bns(t_list **a, t_list **b);

#endif
