/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:25:27 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 13:02:29 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Asigna un nodo objetivo de la pila A para cada nodo de la pila B
static void	set_target_b(t_lst *a, t_lst *b)
{
	t_lst	*current_a;       // Puntero al nodo actual de la pila A
	t_lst	*target_node;     // Nodo objetivo en la pila A para el nodo actual de la pila B
	long	best_match_index; // Valor del mejor número en A que es mayor que el valor en B

	// Recorre todos los nodos de la pila B
	while (b)
	{
		best_match_index = LONG_MAX;  // Inicializa con el valor máximo para encontrar el mejor match
		current_a = a;  // Empieza desde el principio de la pila A

		// Busca el nodo en A que tenga el valor más pequeño que sea mayor que el nodo actual de B
		while (current_a)
		{
			// Si el nodo de A es mayor que el de B pero menor que el mejor match encontrado hasta ahora
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;  // Actualiza el mejor match encontrado
				target_node = current_a;  // Marca este nodo de A como el objetivo para B
			}
			current_a = current_a->next;  // Avanza al siguiente nodo de A
		}

		// Si no se encontró ningún nodo mayor en A, asigna el nodo con el valor mínimo en A como objetivo
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;  // Asigna el nodo objetivo encontrado en A

		b = b->next;  // Avanza al siguiente nodo de B
	}
}

// Inicializa los nodos de la pila B asignando índices y nodos objetivo en A
void	init_nodes_b(t_lst *a, t_lst *b)
{
	current_index(a);    // Asigna índices y mediana a la pila A
	current_index(b);    // Asigna índices y mediana a la pila B
	set_target_b(a, b);  // Establece los nodos objetivo de la pila A para cada nodo de B
}
