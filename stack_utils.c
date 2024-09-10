/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:14:29 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 13:19:37 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cuenta el número de nodos en la lista/pila (stack).
int	stack_len(t_lst *stack)
{
	int	count;  // Contador para el número de nodos

	if (!stack)  // Si la pila está vacía, devuelve 0
		return (0);

	count = 0;
	while (stack)  // Recorre la pila hasta el final
	{
		stack = stack->next;  // Avanza al siguiente nodo
		count++;  // Incrementa el contador
	}
	return (count);  // Devuelve el número total de nodos
}

// Encuentra y devuelve el último nodo de la lista/pila (stack).
t_lst	*find_last(t_lst *stack)
{
	if (!stack)  // Si la pila está vacía, devuelve NULL
		return (NULL);

	// Recorre la pila hasta llegar al último nodo (cuando stack->next es NULL)
	while (stack->next)
		stack = stack->next;

	return (stack);  // Devuelve el último nodo
}

// Verifica si la pila está ordenada en orden ascendente.
t_bool	stack_sorted(t_lst *stack)
{
	if (!stack)  // Si la pila está vacía, se considera ordenada
		return (1);

	// Recorre la pila verificando si cada elemento es mayor que el siguiente
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)  // Si encuentra un desorden, devuelve false
			return (false);
		stack = stack->next;
	}
	return (true);  // Si no hay desorden, devuelve true
}

// Encuentra y devuelve el nodo con el valor más pequeño en la pila.
t_lst	*find_min(t_lst *stack)
{
	long	min;        // Variable para almacenar el valor mínimo
	t_lst	*min_node;  // Puntero al nodo con el valor mínimo

	if (!stack)  // Si la pila está vacía, devuelve NULL
		return (NULL);

	min = LONG_MAX;  // Inicializa min con el valor máximo posible para un long
	while (stack)  // Recorre la pila
	{
		if (stack->nbr < min)  // Si encuentra un valor más pequeño
		{
			min = stack->nbr;  // Actualiza min
			min_node = stack;  // Actualiza el nodo con el valor mínimo
		}
		stack = stack->next;  // Avanza al siguiente nodo
	}
	return (min_node);  // Devuelve el nodo con el valor más pequeño
}

// Encuentra y devuelve el nodo con el valor más grande en la pila.
t_lst	*find_max(t_lst *stack)
{
	long	max;        // Variable para almacenar el valor máximo
	t_lst	*max_node;  // Puntero al nodo con el valor máximo

	if (!stack)  // Si la pila está vacía, devuelve NULL
		return (NULL);

	max = LONG_MIN;  // Inicializa max con el valor mínimo posible para un long
	while (stack)  // Recorre la pila
	{
		if (stack->nbr > max)  // Si encuentra un valor más grande
		{
			max = stack->nbr;  // Actualiza max
			max_node = stack;  // Actualiza el nodo con el valor máximo
		}
		stack = stack->next;  // Avanza al siguiente nodo
	}
	return (max_node);  // Devuelve el nodo con el valor más grande
}
