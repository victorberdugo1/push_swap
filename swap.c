/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:29:48 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:28:15 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Intercambia los dos primeros nodos de la lista apuntada por `head`.
// Asume que `head` es un puntero a un puntero a la cabeza de la lista.
static void	swap(t_lst **head)
{
	if (!*head || !(*head)->next)
		return ;  // La lista está vacía o tiene un solo nodo; no se puede intercambiar nada.

	// Actualiza el puntero a la cabeza de la lista para que apunte al segundo nodo.
	*head = (*head)->next;

	// Actualiza los punteros de los nodos para completar el intercambio.
	(*head)->prev->prev = *head;          // El nuevo primer nodo apunta a sí mismo como anterior.
	(*head)->prev->next = (*head)->next;  // El antiguo primer nodo ahora es el segundo.

	if ((*head)->next)
		(*head)->next->prev = (*head);  // El siguiente nodo apunta al nuevo primer nodo.

	(*head)->next = (*head)->prev;  // El nuevo primer nodo apunta al antiguo primer nodo.
	(*head)->prev = NULL;          // El nuevo primer nodo no tiene nodo anterior.
}

// Intercambia los dos primeros nodos de la lista `a` y, si es necesario, imprime el comando.
void	sa(t_lst **a, t_bool print)
{
	swap(a);
	if (!print)
		ft_printf("sa\n");
}

// Intercambia los dos primeros nodos de la lista `b` y, si es necesario, imprime el comando.
void	sb(t_lst **b, t_bool print)
{
	swap(b);
	if (!print)
		ft_printf("sb\n");
}

// Intercambia los dos primeros nodos de las listas `a` y `b` y, si es necesario, imprime el comando.
void	ss(t_lst **a, t_lst **b, t_bool print)
{
	swap(a);
	swap(b);
	if (!print)
		ft_printf("ss\n");
}
