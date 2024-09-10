/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:34:42 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:19:41 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Realiza una rotación inversa en la pila "stack".
// Mueve el último nodo de la pila al principio.
static void	rev_rotate(t_lst **stack)
{
	t_lst	*last;

	// Si la pila está vacía o solo tiene un nodo, no se hace nada.
	if (!*stack || !(*stack)->next)
		return ;

	// Encuentra el último nodo de la pila.
	last = find_last(*stack);

	// Desconecta el último nodo de su posición actual.
	last->prev->next = NULL;

	// Coloca el último nodo al principio de la pila.
	last->next = *stack;  // El siguiente nodo del último ahora será el primer nodo original.
	last->prev = NULL;    // El nuevo primer nodo no tiene predecesor.
	*stack = last;        // Actualiza el puntero de la pila para que apunte al nuevo primer nodo.
	last->next->prev = last;  // Actualiza el puntero 'prev' del segundo nodo de la pila.
}

// Realiza la operación "rra" (reverse rotate a) en la pila "a".
// Mueve el último nodo de "a" al frente y, si 'print' es false, imprime la operación.
void	rra(t_lst **a, t_bool print)
{
	rev_rotate(a);  // Llama a la función rev_rotate para realizar la rotación inversa.

	// Si 'print' es false, imprime "rra".
	if (!print)
		ft_printf("rra\n");
}

// Realiza la operación "rrb" (reverse rotate b) en la pila "b".
// Mueve el último nodo de "b" al frente y, si 'print' es false, imprime la operación.
void	rrb(t_lst **b, t_bool print)
{
	rev_rotate(b);  // Llama a la función rev_rotate para realizar la rotación inversa.

	// Si 'print' es false, imprime "rrb".
	if (!print)
		ft_printf("rrb\n");
}

// Realiza la operación "rrr" (reverse rotate a y b) en las pilas "a" y "b" simultáneamente.
// Mueve el último nodo de ambas pilas al frente y, si 'print' es false, imprime la operación.
void	rrr(t_lst **a, t_lst **b, t_bool print)
{
	rev_rotate(a);  // Realiza la rotación inversa en la pila "a".
	rev_rotate(b);  // Realiza la rotación inversa en la pila "b".

	// Si 'print' es false, imprime "rrr".
	if (!print)
		ft_printf("rrr\n");
}

