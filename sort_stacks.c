/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:35:35 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:34:53 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotación o rotación inversa en ambas pilas hasta que el nodo objetivo esté en la posición deseada
static void rotate_or_rev_both(t_lst **a, t_lst **b, t_lst *cheap, t_bool rot)
{
    if (rot)
    {
        // Realiza la rotación (rr) mientras el nodo en b no sea el nodo objetivo y el nodo más barato en a no sea el nodo más barato
        while (*b != cheap->target_node && *a != cheap)
            rr(a, b, false);
    }
    else
    {
        // Realiza la rotación inversa (rrr) en el mismo caso
        while (*b != cheap->target_node && *a != cheap)
            rrr(a, b, false);
    }
    // Actualiza los índices de los nodos después de las rotaciones
    current_index(*a);
    current_index(*b);
}

// Mueve el nodo más barato desde la pila a a la pila b
static void move_a_to_b(t_lst **a, t_lst **b)
{
    t_lst *cheap;

    cheap = get_cheapest(*a);  // Encuentra el nodo más barato en a
    // Decide el tipo de rotación basándose en la posición relativa del nodo más barato y su nodo objetivo
    if (cheap->above_median && cheap->target_node->above_median)
        rotate_or_rev_both(a, b, cheap, true);
    else if (!(cheap->above_median) && !(cheap->target_node->above_median))
        rotate_or_rev_both(a, b, cheap, false);
    // Prepara los nodos para el movimiento y realiza el movimiento de la pila
    prep_for_push(a, cheap, 'a');
    prep_for_push(b, cheap->target_node, 'b');
    pb(b, a, false);  // Mueve el nodo desde a a b
}

// Mueve el nodo desde la pila b a la pila a
static void move_b_to_a(t_lst **a, t_lst **b)
{
    // Prepara el nodo objetivo en a y mueve el nodo desde b a a
    prep_for_push(a, (*b)->target_node, 'a');
    pa(a, b, false);  // Mueve el nodo desde b a a
}

// Coloca el nodo mínimo en la parte superior de la pila a
static void min_on_top(t_lst **a)
{
    // Mueve el nodo mínimo al tope de la pila a usando rotaciones y rotaciones inversas
    while ((*a)->nbr != find_min(*a)->nbr)
    {
        if (find_min(*a)->above_median)
            ra(a, false);  // Rotación hacia arriba
        else
            rra(a, false);  // Rotación hacia abajo
    }
}

// Función principal para ordenar las pilas a y b
void sort_stacks(t_lst **a, t_lst **b)
{
    int len_a;

    len_a = stack_len(*a);  // Obtiene la longitud de la pila a
    // Mueve elementos de a a b si la longitud es mayor que 3 y la pila no está ordenada
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    if (len_a-- > 3 && !stack_sorted(*a))
        pb(b, a, false);
    // Mueve los elementos a b y ordena los primeros 3 elementos en a
    while (len_a-- > 3 && !stack_sorted(*a))
    {
        init_nodes_a(*a, *b);
        move_a_to_b(a, b);
    }
    sort_three(a);  // Ordena los 3 elementos restantes en a
    // Mueve los elementos de b a a
    while (*b)
    {
        init_nodes_b(*a, *b);
        move_b_to_a(a, b);
    }
    // Actualiza los índices y coloca el nodo mínimo en la parte superior
    current_index(*a);
    min_on_top(a);
}
