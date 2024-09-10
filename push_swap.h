/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vberdugo <vberdugo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 14:18:49 by vberdugo          #+#    #+#             */
/*   Updated: 2024/09/10 12:33:58 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Librerías necesarias
# include <stdlib.h>      // Para funciones de memoria dinámica y valores NULL
# include "libft/libft.h" // Biblioteca personal para funciones auxiliares

// Definición de límites para enteros largos y enteros comunes
# define LONG_MAX 2147483647L
# define LONG_MIN -2147483648L
# define INT_MAX 2147483647
# define INT_MIN -2147483648

// Definición de un tipo booleano personalizado con dos valores: false (0) y true (1)
typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

// Definición de una estructura para los nodos de la lista enlazada doble
typedef struct s_lst
{
	int				nbr;            // Valor numérico del nodo
	int				index;          // Índice del nodo
	int				push_cost;      // Costo de empuje para operaciones de 'push'
	t_bool			above_median;   // Indica si el número está por encima de la mediana
	t_bool			cheapest;       // Indica si es el nodo con menor costo
	struct s_lst	*target_node;   // Puntero a un nodo objetivo
	struct s_lst	*next;          // Puntero al siguiente nodo en la lista
	struct s_lst	*prev;          // Puntero al nodo anterior en la lista
}	t_lst;

// Funciones para manejar errores y liberar memoria
int		error_syntax(char *str_n);      // Verifica errores de sintaxis en los argumentos de entrada
int		error_duplicate(t_lst *a, int n); // Verifica si hay números duplicados en la lista
void	free_stack(t_lst **stack);       // Libera la memoria del stack completo
void	free_errors(t_lst **a);          // Libera memoria y maneja errores

// Funciones de inicialización y utilidades
void	init_stack_a(t_lst **a, char **argv);  // Inicializa la pila A a partir de los argumentos
char	**split(char *s, char c);        // Divide una cadena por un delimitador
void	init_nodes_a(t_lst *a, t_lst *b); // Inicializa los nodos de la pila A
void	init_nodes_b(t_lst *a, t_lst *b); // Inicializa los nodos de la pila B
void	current_index(t_lst *stack);      // Actualiza el índice actual de cada nodo
void	set_cheapest(t_lst *stack);       // Marca el nodo con el costo más bajo
t_lst	*get_cheapest(t_lst *stack);      // Obtiene el nodo más barato para mover
void	prep_for_push(t_lst **s, t_lst *n, char c); // Prepara un nodo para una operación de 'push'
int		stack_len(t_lst *stack);         // Calcula la longitud de la pila
t_lst	*find_last(t_lst *stack);         // Encuentra el último nodo de la pila
t_bool	stack_sorted(t_lst *stack);       // Verifica si la pila está ordenada
t_lst	*find_min(t_lst *stack);          // Encuentra el valor mínimo en la pila
t_lst	*find_max(t_lst *stack);          // Encuentra el valor máximo en la pila

// Operaciones en la pila A y B (swap, rotate, reverse, push)
void	sa(t_lst **a, t_bool print);      // Intercambia los dos primeros elementos de la pila A
void	sb(t_lst **b, t_bool print);      // Intercambia los dos primeros elementos de la pila B
void	ss(t_lst **a, t_lst **b, t_bool print); // Intercambia los dos primeros elementos de ambas pilas
void	ra(t_lst **a, t_bool print);      // Rota la pila A hacia arriba
void	rb(t_lst **b, t_bool print);      // Rota la pila B hacia arriba
void	rr(t_lst **a, t_lst **b, t_bool print); // Rota ambas pilas hacia arriba
void	rra(t_lst **a, t_bool print);     // Rota la pila A hacia abajo
void	rrb(t_lst **b, t_bool print);     // Rota la pila B hacia abajo
void	rrr(t_lst **a, t_lst **b, t_bool print); // Rota ambas pilas hacia abajo
void	pa(t_lst **a, t_lst **b, t_bool print); // Realiza un 'push' de B a A
void	pb(t_lst **b, t_lst **a, t_bool print); // Realiza un 'push' de A a B

// Algoritmos de ordenamiento
void	sort_three(t_lst **a);            // Ordena 3 elementos en la pila A
void	sort_stacks(t_lst **a, t_lst **b); // Ordena las pilas A y B utilizando varios algoritmos

// Función de utilidad para liberar una matriz de cadenas
void	free_splited_str(char **splited_str); // Libera la memoria de una matriz de cadenas (resultado de split)

#endif

