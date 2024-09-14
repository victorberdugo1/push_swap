/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:34:57 by victor            #+#    #+#             */
/*   Updated: 2024/09/05 13:32:58 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_lst **stack)
{
	t_lst	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_lst **a, t_bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_lst **b, t_bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_lst **a, t_lst **b, t_bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}
