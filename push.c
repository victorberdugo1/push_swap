/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:27:06 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:18:22 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función auxiliar que realiza la operación "push" entre dos pilas.
// Toma el primer nodo de la pila "src" y lo mueve al frente de la pila "dst".
static void	push(t_lst **dst, t_lst **src)
{
	t_lst	*push_node;

	// Si la pila de origen está vacía, no se hace nada.
	if (!*src)
		return ;

	// El nodo que será movido es el primero de la pila "src".
	push_node = *src;
	// Actualiza la pila "src" para que su primer nodo ahora sea el siguiente.
	*src = (*src)->next;

	// Si hay más nodos en "src", el nuevo primer nodo no debe tener predecesor.
	if (*src)
		(*src)->prev = NULL;

	// El nodo movido no tendrá predecesor.
	push_node->prev = NULL;

	// Si la pila de destino "dst" está vacía, el nodo movido será el único.
	if (!*dst)
	{
		*dst = push_node;
		push_node->next = NULL;
	}
	// Si "dst" ya tiene nodos, coloca el nodo movido al frente de "dst".
	else
	{
		push_node->next = *dst;  // El nodo siguiente del nuevo nodo será el anterior primer nodo de "dst".
		push_node->next->prev = push_node;  // Actualiza el puntero 'prev' del anterior primer nodo de "dst".
		*dst = push_node;  // Actualiza el puntero "dst" para que apunte al nuevo primer nodo.
	}
}

// Realiza la operación "pa", que mueve el primer nodo de la pila "b" a la pila "a".
// Si 'print' es false, imprime la operación realizada.
void	pa(t_lst **a, t_lst **b, t_bool print)
{
	push(a, b);  // Llama a la función 'push' para mover el nodo de "b" a "a".

	// Si 'print' es false, imprime la operación "pa".
	if (!print)
		ft_printf("pa\n");
}

// Realiza la operación "pb", que mueve el primer nodo de la pila "a" a la pila "b".
// Si 'print' es false, imprime la operación realizada.
void	pb(t_lst **b, t_lst **a, t_bool print)
{
	push(b, a);  // Llama a la función 'push' para mover el nodo de "a" a "b".

	// Si 'print' es false, imprime la operación "pb".
	if (!print)
		ft_printf("pb\n");
}
