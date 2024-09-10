/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:22:07 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 13:08:17 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Asigna un índice a cada nodo de la pila y marca si está por encima de la mediana
void	current_index(t_lst *stack)
{
	int	i;       // Índice actual
	int	median;  // Mediana de la longitud de la pila

	i = 0;
	if (!stack)  // Si la pila está vacía, no hace nada
		return ;

	// Calcula la mediana dividiendo la longitud de la pila entre 2
	median = stack_len(stack) / 2;

	// Asigna el índice a cada nodo y establece si está por encima de la mediana
	while (stack)
	{
		stack->index = i;  // Asigna el índice actual al nodo
		if (i <= median)
			stack->above_median = true;  // Marca si el índice está por debajo o en la mediana
		else
			stack->above_median = false; // Marca si está por encima de la mediana
		stack = stack->next;  // Avanza al siguiente nodo
		++i;  // Incrementa el índice
	}
}

// Establece el nodo objetivo para cada nodo de la pila A en base a la pila B
static void	set_target_a(t_lst *a, t_lst *b)
{
	t_lst	*current_b;       // Puntero al nodo actual de la pila B
	t_lst	*target_node;     // Nodo objetivo en la pila B
	long	best_match_index; // Mejor número menor que 'a->nbr' en la pila B

	while (a)  // Recorre cada nodo en la pila A
	{
		best_match_index = LONG_MIN;  // Inicializa el mejor índice con un valor mínimo
		current_b = b;  // Empieza desde el principio de la pila B

		// Busca el mejor nodo en B para el nodo actual de A
		while (current_b)
		{
			// Si el nodo de B es menor que el de A pero mayor que el actual mejor match
			if (current_b->nbr < a->nbr && current_b->nbr > best_match_index)
			{
				best_match_index = current_b->nbr;  // Actualiza el mejor número encontrado
				target_node = current_b;  // Marca el nodo de B como el objetivo
			}
			current_b = current_b->next;  // Avanza al siguiente nodo en B
		}

		// Si no se encontró ningún match en B, establece el nodo con el valor máximo en B como objetivo
		if (best_match_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;  // Asigna el nodo objetivo

		a = a->next;  // Avanza al siguiente nodo en A
	}
}

// Calcula el costo de realizar la operación 'push' para cada nodo de la pila A
static void	cost_analysis_a(t_lst *a, t_lst *b)
{
	int	len_a;  // Longitud de la pila A
	int	len_b;  // Longitud de la pila B

	len_a = stack_len(a);  // Obtiene la longitud de la pila A
	len_b = stack_len(b);  // Obtiene la longitud de la pila B

	// Calcula el costo de 'push' para cada nodo de A
	while (a)
	{
		a->push_cost = a->index;  // Inicialmente, el costo es igual al índice del nodo

		// Si el nodo está por debajo de la mediana, su costo es el número de movimientos restantes
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);

		// Añade el costo de mover el nodo objetivo en la pila B
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);

		a = a->next;  // Avanza al siguiente nodo en A
	}
}

// Encuentra el nodo con el menor costo de 'push' y lo marca como el más barato
void	set_cheapest(t_lst *stack)
{
	long	cheapest_value;  // Valor del menor costo encontrado
	t_lst	*cheapest_node;  // Nodo con el costo más bajo

	if (!stack)  // Si la pila está vacía, no hace nada
		return ;

	cheapest_value = LONG_MAX;  // Inicializa el menor costo con un valor máximo

	// Recorre todos los nodos para encontrar el de menor costo
	while (stack)
	{
		// Si el costo del nodo actual es menor que el valor actual más barato
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;  // Actualiza el menor costo
			cheapest_node = stack;  // Marca el nodo como el más barato
		}
		stack = stack->next;  // Avanza al siguiente nodo
	}

	// Marca el nodo más barato
	cheapest_node->cheapest = true;
}

// Inicializa los nodos de la pila A y realiza todos los cálculos necesarios para el ordenamiento
void	init_nodes_a(t_lst *a, t_lst *b)
{
	current_index(a);          // Asigna índices y mediana a la pila A
	current_index(b);          // Asigna índices y mediana a la pila B
	set_target_a(a, b);        // Establece los nodos objetivo en la pila B para cada nodo de A
	cost_analysis_a(a, b);     // Calcula el costo de realizar un 'push' para cada nodo de A
	set_cheapest(a);           // Marca el nodo con el menor costo como el más barato
}
