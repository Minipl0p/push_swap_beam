/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:25:23 by pchazalm          #+#    #+#             */
/*   Updated: 2026/01/02 12:33:23 by miniplop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

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
char	*ft_pars(int ac, char **av);
int		is_args_valid(char **args);
void	ft_free_clear(t_list *lst, t_content *content);
void	ft_skip_space(char *join, int *i);
char	*ft_skip_char(char *str, char c, int in_out);
int		ft_check_double(t_list *lst);
t_list	*ft_init_lst(char *str);

//LIS
int		*copy_values(t_list *lst, int size);
void	reset_is_lis(t_list *lst);
int		set_lis(t_list *lst);
void	push_non_lis(t_list **a, t_list **b);

//moves
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
void	apply_best_move(t_list **a, t_list **b, t_cost m);

//turkish
void	calc_costs(t_list *dest, t_list *src, t_cost *c);
int		ft_abs(int x);
int		ft_max(int a, int b);
int		find_min(t_list *a);
int		rotation_cost(int i, int size);
int		index_of(t_list *lst, int value);

//Others
void	min_to_top(t_list **a, int len);
int		get_max(t_list *a);
void	mini_sort(t_list **a, t_list **b);
int		is_sorted(t_list *a);
void	final_rotate(t_list **a);
void	get_medians(t_list *a, int *med);
int		lstsize_nonx(t_list *a, int x);

#endif
