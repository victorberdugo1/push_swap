/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:34:57 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:20:47 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Realiza una rotación hacia arriba en la pila "stack".
// Mueve el primer nodo de la pila al final.
static void	rotate(t_lst **stack)
{
	t_lst	*last_node;

	// Si la pila está vacía o solo tiene un nodo, no se hace nada.
	if (!*stack || !(*stack)->next)
		return ;

	// Encuentra el último nodo de la pila.
	last_node = find_last(*stack);

	// Mueve el primer nodo al final.
	last_node->next = *stack;        // El último nodo ahora apunta al primer nodo.
	*stack = (*stack)->next;         // El segundo nodo se convierte en el primer nodo.
	(*stack)->prev = NULL;           // El nuevo primer nodo no tiene predecesor.
	last_node->next->prev = last_node; // El antiguo primer nodo ahora apunta hacia atrás al último nodo.
	last_node->next->next = NULL;    // El antiguo primer nodo se convierte en el nuevo último nodo.
}

// Realiza la operación "ra" (rotate a) en la pila "a".
// Mueve el primer nodo de "a" al final y, si 'print' es false, imprime la operación.
void	ra(t_lst **a, t_bool print)
{
	rotate(a);  // Llama a la función rotate para realizar la rotación en la pila "a".

	// Si 'print' es false, imprime "ra".
	if (!print)
		ft_printf("ra\n");
}

// Realiza la operación "rb" (rotate b) en la pila "b".
// Mueve el primer nodo de "b" al final y, si 'print' es false, imprime la operación.
void	rb(t_lst **b, t_bool print)
{
	rotate(b);  // Llama a la función rotate para realizar la rotación en la pila "b".

	// Si 'print' es false, imprime "rb".
	if (!print)
		ft_printf("rb\n");
}

// Realiza la operación "rr" (rotate a y b) en las pilas "a" y "b" simultáneamente.
// Mueve el primer nodo de ambas pilas al final y, si 'print' es false, imprime la operación.
void	rr(t_lst **a, t_lst **b, t_bool print)
{
	rotate(a);  // Realiza la rotación en la pila "a".
	rotate(b);  // Realiza la rotación en la pila "b".

	// Si 'print' es false, imprime "rr".
	if (!print)
		ft_printf("rr\n");
}
