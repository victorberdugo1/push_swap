/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 13:44:57 by vberdugo          #+#    #+#             */
/*   Updated: 2024/09/14 15:02:59 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** error_syntax:
** Verifica si la cadena pasada como argumento es un número válido.
** Retorna 1 si hay un error en la sintaxis (carácter inválido, signo, etc.).
** Retorna 0 si no hay error.
**
** Línea 28: Verifica si el primer carácter es un signo o un dígito.
** Línea 30: Si el primer carácter es un signo, next carácter es número.
** Línea 32: Recorre el resto de la cadena y cada carácter debe ser dígito.
** Línea 37: Retorna 0 si no hay errores de sintaxis.
*/
int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (ft_isdigit(*str_n))))
		return (1);
	if ((*str_n == 43 || *str_n == 45) && !(ft_isdigit(str_n[1])))
		return (1);
	while (*++str_n)
	{
		if (!(ft_isdigit(*str_n)))
			return (1);
	}
	return (0);
}

/*
** error_duplicate:
** Verifica si el número 'n' ya existe en la lista 'a'.
** Retorna 1 si encuentra un duplicado, de lo contrario retorna 0.
**
** Línea 52: Si la lista está vacía, no hay duplicados.
** Línea 54: Recorre la lista para buscar duplicados.
** Línea 57: Si encuentra el número duplicado, retorna 1.
** Línea 60: Retorna 0 si no se encontraron duplicados.
*/
int	error_duplicate(t_lst *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
	return (0);
}

/*
** free_stack:
** Libera la memoria de la pila (lista enlazada) y la pone a NULL.
** Recorre la lista liberando cada nodo.
**
** Línea 77: Si la pila ya está vacía, no hace nada.
** Línea 80: Recorre la lista y libera cada nodo.
** Línea 87: Pone la pila a NULL después de liberar todos los nodos.
*/
void	free_stack(t_lst **stack)
{
	t_lst	*tmp;
	t_lst	*current;

	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

/*
** free_errors:
** Libera la pila y muestra un mensaje de error antes de salir del programa.
** Se utiliza cuando ocurre un error en la validación o ejecución.
**
** Línea 101: Llama a free_stack para liberar la memoria de la pila.
** Línea 102: Muestra el mensaje de error "Error\n".
** Línea 103: Termina la ejecución del programa con un código de error.
*/
void	free_errors(t_lst **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

/*
** main:
** Función principal del programa Push_swap.
** Se encarga de inicializar la pila 'a', validar los argumentos y ordena.
**
** Línea 127: Inicializa las pilas 'a' y 'b' como NULL y splited_str.
** Línea 130: Si no hay argumentos o el único argumento está vacío, retorna.
** Línea 132: Si solo hay un argumento, divide la cadena en múltiples números.
** Línea 137: Inicializa la pila 'a' con los números proporcionados en 'argv'.
** Línea 138: Si la pila no está ya ordenada, procede a ordenar.
** Línea 140: Para pilas de 2 elementos, usa 'sa' para intercambiar.
** Línea 142: Para pilas de 3 elementos, usa el algoritmo de 3 números.
** Línea 144: Para pilas mayores de 3 elementos, usa un algoritmo más complejo.
** Línea 147: Libera la memoria utilizada y finaliza el programa.
*/
int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	char	**splited_str;

	splited_str = NULL;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		splited_str = split(argv[1], ' ');
		argv = splited_str - 1;
	}
	init_stack_a(&a, argv + 1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	return (free_splited_str(splited_str), free_stack(&a), 0);
}
