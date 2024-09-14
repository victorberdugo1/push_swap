/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:27:06 by victor            #+#    #+#             */
/*   Updated: 2024/09/14 15:44:52 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_lst **dst, t_lst **src)
{
	t_lst	*push_node;

	if (!*src)
		return ;
	push_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	push_node->prev = NULL;
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	else
	{
		push_node->next = *dst;
		push_node->next->prev = push_node;
		*dst = push_node;
	}
}

void	pa(t_lst **a, t_lst **b, t_bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_lst **b, t_lst **a, t_bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}
