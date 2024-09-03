/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:28:29 by victor            #+#    #+#             */
/*   Updated: 2024/09/03 19:17:20 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+' || *str_n == '-' || (*str_n >= '0' && *str_n <= '9')))
		return (1);
	if ((*str_n == 43 || *str_n == 45) && !(str_n[1] >= '0' && str_n[1] <= '9'))
		return (1);
	while (*++str_n)
	{
		if (!(*str_n >= '0' && *str_n <= '9'))
			return (1);
	}
	return (0);
}

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

void	free_errors(t_lst **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}

#include <stdio.h>
void print_list_and_check_sorted(t_lst *head) {
    t_lst *current = head;
    int sorted = 1;  // Para verificar si está ordenado

    printf("Lista de nodos:\n");
    while (current && current->next) {
        printf("%d -> ", current->nbr);

        // Si el valor actual es mayor que el siguiente, no está ordenado
        if (current->nbr > current->next->nbr) {
            sorted = 0;
        }

        current = current->next;
    }

    if (current) {
        printf("%d\n", current->nbr);  // Imprime el último valor
    }

    // Verificar si la lista está ordenada
    if (sorted) {
        printf("La lista está ordenada.\n");
    } else {
        printf("La lista no está ordenada.\n");
    }
}

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
	//print_list_and_check_sorted(a);
	return (free_splited_str(splited_str), free_stack(&a), 0);
}
