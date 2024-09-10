/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:10:38 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 13:06:03 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Convierte una cadena de caracteres a un número entero largo (long), manejando signos y espacios en blanco.
static long	ft_atol(const char *s)
{
	long	result;  // Almacena el valor numérico resultante
	int		sign;    // Indica si el número es positivo o negativo

	result = 0;
	sign = 1;

	// Ignora los espacios en blanco y caracteres de control al principio de la cadena
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;

	// Maneja el signo si existe ('-' o '+')
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')  // Si es negativo, ajusta el signo
			sign = -1;
		s++;
	}

	// Convierte los caracteres numéricos en un número largo (long)
	while (ft_isdigit(*s))
		result = result * 10 + (*s++ - '0');

	return (result * sign);  // Devuelve el resultado con el signo aplicado
}

// Añade un nuevo nodo al final de la pila con el valor n.
static void	append_node(t_lst **stack, int n)
{
	t_lst	*node;       // Nuevo nodo que se va a añadir
	t_lst	*last_node;  // Último nodo actual de la pila

	if (!stack)  // Si la pila es nula, no se hace nada
		return ;

	// Reserva memoria para el nuevo nodo
	node = malloc(sizeof(t_lst));
	if (!node)  // Si no se puede reservar memoria, no se hace nada
		return ;

	node->next = NULL;  // El siguiente nodo es NULL, ya que será el último nodo
	node->nbr = n;      // Asigna el valor n al nodo

	if (!(*stack))  // Si la pila está vacía, el nuevo nodo es el primero
	{
		*stack = node;
		node->prev = NULL;  // No hay nodo anterior
	}
	else  // Si ya hay nodos en la pila, se añade al final
	{
		last_node = find_last(*stack);  // Encuentra el último nodo
		last_node->next = node;         // Conecta el último nodo al nuevo
		node->prev = last_node;         // Conecta el nuevo nodo al anterior
	}
}

// Inicializa la pila A con los valores del arreglo argv, validando errores y duplicados.
void	init_stack_a(t_lst **a, char **argv)
{
	long	n;  // Valor numérico convertido de la cadena
	int		i;  // Índice para recorrer argv

	i = 0;
	while (argv[i])  // Recorre cada argumento en argv
	{
		// Verifica si la cadena tiene una sintaxis inválida
		if (error_syntax(argv[i]))
			free_errors(a);  // Libera la pila y muestra un error

		n = ft_atol(argv[i]);  // Convierte la cadena a un número largo

		// Verifica si el número está fuera del rango permitido para enteros
		if (n > INT_MAX || n < INT_MIN)
			free_errors(a);

		// Verifica si hay números duplicados en la pila
		if (error_duplicate(*a, (int)n))
			free_errors(a);

		// Añade el número como un nuevo nodo en la pila
		append_node(a, (int)n);
		i++;
	}
}

// Encuentra y devuelve el nodo con el costo más barato de la pila.
t_lst	*get_cheapest(t_lst *stack)
{
	if (!stack)  // Si la pila está vacía, devuelve NULL
		return (NULL);

	// Recorre la pila para encontrar el nodo marcado como el más barato
	while (stack)
	{
		if (stack->cheapest)
			return (stack);  // Devuelve el nodo más barato
		stack = stack->next;  // Avanza al siguiente nodo
	}
	return (NULL);  // Si no se encuentra, devuelve NULL
}

// Prepara la pila para ejecutar la operación 'push', moviendo el nodo superior a la posición correcta.
void	prep_for_push(t_lst **stack, t_lst *top_node, char stack_name)
{
	// Mientras el nodo actual no sea el nodo superior deseado
	while (*stack != top_node)
	{
		if (stack_name == 'a')  // Si la pila es A
		{
			if (top_node->above_median)  // Si el nodo está por encima de la mediana
				ra(stack, false);        // Rota hacia arriba
			else
				rra(stack, false);       // Rota hacia abajo
		}
		else if (stack_name == 'b')  // Si la pila es B
		{
			if (top_node->above_median)  // Si el nodo está por encima de la mediana
				rb(stack, false);        // Rota hacia arriba
			else
				rrb(stack, false);       // Rota hacia abajo
		}
	}
}
