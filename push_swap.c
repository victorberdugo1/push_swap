/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:28:29 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 12:44:23 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Función que verifica si una cadena es un número válido (incluyendo signos '+' o '-')
int	error_syntax(char *str_n)
{
    // Verifica si el primer carácter es un signo o un número
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);

	// Verifica si después de un signo '+' o '-' hay un número
	if ((*str_n == 43 || *str_n == 45) && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);

	// Recorre el resto de la cadena y verifica que todos los caracteres sean dígitos
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);  // Retorna 0 si la cadena es válida
}

// Función que verifica si el número 'n' está duplicado en la lista enlazada 'a'
int	error_duplicate(t_lst *a, int n)
{
	if (!a)  // Si la lista está vacía, no hay duplicados
		return (0);

	// Recorre la lista 'a' buscando duplicados
	while (a)
	{
		if (a->nbr == n)  // Si encuentra un número igual, retorna error (1)
			return (1);
		a = a->next;
	}
	return (0);  // Retorna 0 si no hay duplicados
}

// Función que libera la memoria de una pila 'stack' y la deja en NULL
void	free_stack(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*current;

	if (!stack)  // Si la pila es NULL, no hace nada
		return ;

	current = *stack;
	while (current)  // Recorre y libera cada nodo de la pila
	{
		tmp = current->next;
		current->nbr = 0;  // Borra el valor numérico antes de liberar
		free(current);  // Libera el nodo actual
		current = tmp;  // Pasa al siguiente nodo
	}
	*stack = NULL;  // Una vez liberada la pila, asigna NULL
}

// Función que libera la pila 'a' en caso de error y muestra un mensaje de error antes de salir
void	free_errors(t_lst **a)
{
	free_stack(a);  // Libera la pila
	ft_printf("Error\n");  // Muestra el mensaje de error
	exit(1);  // Termina el programa
}

// Función principal del programa
int	main(int argc, char **argv)
{
	t_lst	*a;               // Pila A
	t_lst	*b;               // Pila B
	char	**splited_str;    // Array para cadenas divididas si se pasa una cadena con múltiples números

	splited_str = NULL;
	a = NULL;
	b = NULL;

	// Si no hay argumentos o si el argumento es una cadena vacía, retorna 1
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);

	// Si hay un argumento único (una cadena de números), lo divide en subcadenas
	else if (argc == 2)
	{
		splited_str = split(argv[1], ' ');  // Divide la cadena por espacios
		argv = splited_str - 1;  // Ajusta argv para procesar los números divididos
	}

	// Inicializa la pila A con los valores de los argumentos
	init_stack_a(&a, argv + 1);

	// Si la pila no está ordenada, realiza las operaciones de ordenamiento
	if (!stack_sorted(a))
	{
		// Si la pila tiene solo 2 elementos, intercambia
		if (stack_len(a) == 2)
			sa(&a, false);
		// Si la pila tiene 3 elementos, utiliza un algoritmo para 3 elementos
		else if (stack_len(a) == 3)
			sort_three(&a);
		// Si la pila tiene más de 3 elementos, utiliza el algoritmo completo
		else
			sort_stacks(&a, &b);
	}

	// Libera la memoria utilizada y termina el programa
	return (free_splited_str(splited_str), free_stack(&a), 0);
}

