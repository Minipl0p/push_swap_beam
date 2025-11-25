/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchazalm <pchazalm@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:25:23 by pchazalm          #+#    #+#             */
/*   Updated: 2025/11/25 16:23:13 by pchazalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "../libft/libft.h"

typedef	struct	s_content
{
	int	value;
}				t_content;

typedef struct s_stack
{
    t_list  *top;
    int      size;
}				t_stack;

typedef struct s_state
{
    t_stack a;
    t_stack b;
    int     cost;
    int    *first_seq;   // séquence complète de moves
    int     seq_len;     // longueur de la séquence
}				t_state;

typedef struct s_beam
{
    t_state *states; // tableau de states
    int      count;  // nombre d'états présents
    int      max;    // N
}				t_beam;

typedef struct s_move
{
    int code;   // ex : 0 = ra, 1 = rb, 2 = rr, 3 = rra...
}				t_move;

//Pars
char	*ft_pars(int ac, char **av);
void	ft_free_clear(t_list *lst, t_content *content);
void	ft_skip_space(char *join, int *i);
char	*ft_skip_char(char *str, char c, int in_out);
int		ft_check_double(t_list *lst);
t_list	*ft_init_lst(char *str);

//Beam


//Cost


//Stack


#endif // !PUSH_SWAP_H

