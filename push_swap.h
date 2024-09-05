/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:49 by vberdugo          #+#    #+#             */
/*   Updated: 2024/09/05 13:43:14 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# define LONG_MAX 2147483647L
# define LONG_MIN -2147483648L
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_lst
{
	int				nbr;
	int				index;
	int				push_cost;
	t_bool			above_median;
	t_bool			cheapest;
	struct s_lst	*target_node;
	struct s_lst	*next;
	struct s_lst	*prev;
}	t_lst;

int		error_syntax(char *str_n);
int		error_duplicate(t_lst *a, int n);
void	free_stack(t_lst **stack);
void	free_errors(t_lst **a);
void	init_stack_a(t_lst **a, char **argv);
char	**split(char *s, char c);
void	init_nodes_a(t_lst *a, t_lst *b);
void	init_nodes_b(t_lst *a, t_lst *b);
void	current_index(t_lst *stack);
void	set_cheapest(t_lst *stack);
t_lst	*get_cheapest(t_lst *stack);
void	prep_for_push(t_lst **s, t_lst *n, char c);
int		stack_len(t_lst *stack);
t_lst	*find_last(t_lst *stack);
t_bool	stack_sorted(t_lst *stack);
t_lst	*find_min(t_lst *stack);
t_lst	*find_max(t_lst *stack);
void	sa(t_lst **a, t_bool print);
void	sb(t_lst **b, t_bool print);
void	ss(t_lst **a, t_lst **b, t_bool print);
void	ra(t_lst **a, t_bool print);
void	rb(t_lst **b, t_bool print);
void	rr(t_lst **a, t_lst **b, t_bool print);
void	rra(t_lst **a, t_bool print);
void	rrb(t_lst **b, t_bool print);
void	rrr(t_lst **a, t_lst **b, t_bool print);
void	pa(t_lst **a, t_lst **b, t_bool print);
void	pb(t_lst **b, t_lst **a, t_bool print);
void	sort_three(t_lst **a);
void	sort_stacks(t_lst **a, t_lst **b);
void	free_splited_str(char **splited_str);

#endif
