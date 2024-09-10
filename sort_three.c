/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:05:02 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:35:34 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Ordena exactamente tres elementos en la pila a
void sort_three(t_lst **a)
{
    t_lst *biggest_node;

    // Encuentra el nodo con el valor máximo en la pila a
    biggest_node = find_max(*a);

    // Si el nodo con el valor máximo es el primer nodo
    if (biggest_node == *a)
        ra(a, false);  // Realiza una rotación hacia arriba para mover el máximo al final

    // Si el nodo con el valor máximo es el segundo nodo
    else if ((*a)->next == biggest_node)
        rra(a, false);  // Realiza una rotación inversa para mover el máximo al principio

    // Si el primer nodo es mayor que el segundo nodo, intercámbialos
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);  // Intercambia los dos primeros nodos
}
