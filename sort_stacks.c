/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:35:35 by victor            #+#    #+#             */
/*   Updated: 2024/09/05 13:32:59 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_or_rev_both(t_lst **a, t_lst **b, t_lst *cheap, t_bool rotate)
{
	if (rotate)
	{
		while (*b != cheap->target_node && *a != cheap)
			rr(a, b, false);
	}
	else
	{
		while (*b != cheap->target_node && *a != cheap)
			rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}

static void	move_a_to_b(t_lst **a, t_lst **b)
{
	t_lst	*cheap;

	cheap = get_cheapest(*a);
	if (cheap->above_median && cheap->target_node->above_median)
		rotate_or_rev_both(a, b, cheap, true);
	else if (!(cheap->above_median) && !(cheap->target_node->above_median))
		rotate_or_rev_both(a, b, cheap, false);
	prep_for_push(a, cheap, 'a');
	prep_for_push(b, cheap->target_node, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_lst **a, t_lst **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_lst **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_lst **a, t_lst **b)
{
	int	len_a;

	len_a = stack_len(*a);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !stack_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
