/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:05:31 by victor            #+#    #+#             */
/*   Updated: 2024/09/10 14:22:51 by vberdugo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Cuenta el número de palabras en la cadena "s" separadas por el carácter delimitador "c".
static int	count_words(char *s, char c)
{
	int		count;
	t_bool	inside_word;

	count = 0;
	inside_word = false;
	while (*s)
	{
		inside_word = false;
		// Salta los caracteres delimitadores.
		while (*s == c)
			++s;
		// Cuenta las palabras.
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

// Obtiene la siguiente palabra de la cadena "s" que está delimitada por el carácter "c".
// Actualiza el cursor para apuntar al siguiente carácter después de la palabra obtenida.
static char	*get_next_word(char *s, char c, int *cursor)
{
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	// Salta los caracteres delimitadores.
	while (s[*cursor] == c)
		++(*cursor);
	// Calcula la longitud de la siguiente palabra.
	while (s[*cursor + len] != c && s[*cursor + len])
		++len;
	// Aloca memoria para la nueva palabra, incluyendo el carácter nulo.
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	// Copia la palabra a la nueva memoria.
	while (s[*cursor] != c && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';  // Termina la cadena con un carácter nulo.
	return (next_word);
}

// Libera la memoria alocada para el arreglo de cadenas "splited_str".
void	free_splited_str(char **splited_str)
{
	int	i;

	i = 0;
	if (!splited_str)
		return ;
	// Libera cada cadena individual en el arreglo.
	while (splited_str[i] != NULL)
	{
		free(splited_str[i]);
		i++;
	}
	// Libera el arreglo de cadenas.
	free(splited_str);
}

// Divide la cadena "s" en un arreglo de cadenas, usando el carácter delimitador "c".
char	**split(char *s, char c)
{
	int		i;
	int		words;
	int		cursor;
	char	**res;

	i = 0;
	cursor = 0;
	// Cuenta el número de palabras en la cadena.
	words = count_words(s, c);
	// Aloca memoria para el arreglo de punteros a cadenas.
	res = malloc((words + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	// Obtiene cada palabra y la almacena en el arreglo.
	while (i < words)
	{
		res[i] = get_next_word(s, c, &cursor);
		if (!res[i])
		{
			// Si falla la alocación, libera la memoria ya alocada.
			free_splited_str(res);
			return (NULL);
		}
		i++;
	}
	// Marca el final del arreglo con un puntero nulo.
	res[i] = NULL;
	return (res);
}
