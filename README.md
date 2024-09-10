# `push_swap`

## V.1. Reglas

### Descripción General
En este proyecto, trabajas con dos pilas (stacks) denominadas `a` y `b`. Tu objetivo es ordenar los números en la pila `a` en orden ascendente, utilizando un conjunto específico de operaciones permitidas. La pila `b` comienza vacía.

### Operaciones Disponibles

- **`sa` (swap a)**: Intercambia los dos primeros elementos de la pila `a`. No hace nada si hay uno o ningún elemento.
- **`sb` (swap b)**: Intercambia los dos primeros elementos de la pila `b`. No hace nada si hay uno o ningún elemento.
- **`ss` (swap a y swap b)**: Realiza `sa` y `sb` simultáneamente.
- **`pa` (push a)**: Mueve el primer elemento de la pila `b` al principio de la pila `a`. No hace nada si `b` está vacío.
- **`pb` (push b)**: Mueve el primer elemento de la pila `a` al principio de la pila `b`. No hace nada si `a` está vacío.
- **`ra` (rotate a)**: Desplaza todos los elementos de la pila `a` una posición hacia arriba, haciendo que el primer elemento pase a ser el último.
- **`rb` (rotate b)**: Desplaza todos los elementos de la pila `b` una posición hacia arriba, haciendo que el primer elemento pase a ser el último.
- **`rr` (rotate a y rotate b)**: Realiza `ra` y `rb` simultáneamente.
- **`rra` (reverse rotate a)**: Desplaza todos los elementos de la pila `a` una posición hacia abajo, haciendo que el último elemento pase a ser el primero.
- **`rrb` (reverse rotate b)**: Desplaza todos los elementos de la pila `b` una posición hacia abajo, haciendo que el último elemento pase a ser el primero.
- **`rrr` (reverse rotate a y reverse rotate b)**: Realiza `rra` y `rrb` simultáneamente.

## V.2. Ejemplo

A continuación, se muestra un ejemplo de cómo se aplican las instrucciones para ordenar una lista de números:

```sh
Inicialización de a y b:
2
1
3
6
5
8
_ _
a b
```
```sh
Ejecutar `sa`:
1
2
3
6
5
8
_ _
a b
```
```sh
Ejecutar `pb pb pb`:
6 3
5 2
8 1
_ _
a b
```
```sh
Ejecutar `ra rb` (equivale a `rr`):
5 2
8 1
6 3
_ _
a b
```
```sh
Ejecutar `rra rrb` (equivalente a `rrr`):
6 3
5 2
8 1
_ _
a b
```
```sh
Ejecutar `sa`:
5 3
6 2
8 1
_ _
a b
```
```sh
Ejecutar `pa pa pa`:
1
2
3
5
6
8
_ _
a b
```

## V.3. El Programa: `push_swap`

| Aspecto                 | Detalle                                   |
|-------------------------|-------------------------------------------|
| **Nombre del Programa** | `push_swap`                               |
| **Archivos a Entregar** | Makefile, `*.h`, `*.c`                    |
| **Makefile**            | Debe incluir las reglas: `NAME`, `all`, `clean`, `fclean`, `re` |
| **Argumentos**          | Stack `a`: Una lista de números enteros. El primer argumento debe ser el que esté en la parte superior del stack. |
| **Funciones Permitidas**| `read`, `write`, `malloc`, `free`, `exit`, `ft_printf` y cualquier función equivalente creada |
| **Uso de libft**        | Permitido                                 |
| **Descripción**         | Ordenar stacks. |


El programa debe:

- Leer los números del stack `a` y mostrarlos ordenados de menor a mayor.
- Mostrar la lista de instrucciones más corta posible para ordenar el stack `a`.
- Las instrucciones deben separarse utilizando un salto de línea (`\n`).

### Requisitos

- No se permiten variables globales.
- El programa debe mostrar un mensaje de error ("Error\n") en la salida estándar de errores en caso de argumentos inválidos o duplicados.

### Ejemplo de Uso

```sh
$ ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$ ./push_swap 0 one 2 3
Error
```
## V.4. Pruebas de Rendimiento

### Validación Mínima

- Ordenar 100 números aleatorios en menos de 700 operaciones.

### Validación Máxima

- Ordenar 500 números aleatorios en menos de 5500 operaciones.



### Nota Adicional

Se proporcionará un binario para verificar el funcionamiento correcto del programa:

```sh
$ ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$ ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK
```

Si el programa `checker_linux` muestra "KO", significa que la lista de instrucciones generada no ordena los números correctamente.
