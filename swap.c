/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:29:48 by victor            #+#    #+#             */
/*   Updated: 2024/09/05 13:33:03 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_lst **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_lst **a, t_bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

void	sb(t_lst **b, t_bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

void	ss(t_lst **a, t_lst **b, t_bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
