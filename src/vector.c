/*
** vector.c for vector in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Feb 27 19:47:52 2017 Thomas ARBONA
** Last update Mon Mar 13 23:15:28 2017 Thomas ARBONA
*/
#include <unistd.h>
#include <stdlib.h>
#include "vector.h"

int	vector_create(t_vector *vector)
{
  vector->size = 0;
  vector->capacity = VECTOR_INIT_CAPACITY;
  if (!(vector->items = malloc(sizeof(void*) * vector->capacity)))
    return (-1);
  return (0);
}

int	vector_resize(t_vector *vector, int capacity)
{
  int	index;
  void	**items;

  if (!(items = malloc(sizeof(void*) * capacity)))
    return (-1);
  index = 0;
  while (index < vector->size)
    {
      items[index] = vector->items[index];
      index += 1;
    }
  vector_destroy(vector);
  vector->items = items;
  vector->capacity = capacity;
}

void	vector_foreach(t_vector *vector, void (*func)(void*, int))
{
  int	index;

  index = 0;
  while (index < vector->size)
    {
      func(vector->items[index], index);
      index += 1;
    }
}

void	vector_sort(t_vector *vector, int (*cmp)(void*, void*))
{
  void	*item;
  int	index;

  index = 0;
  while (index < vector->size - 1)
    {
      if (cmp(vector->items[index], vector->items[index + 1]))
	{
	  item = vector->items[index];
	  vector->items[index] = vector->items[index + 1];
	  vector->items[index + 1] = item;
	}
      index += 1;
    }
}

void	vector_destroy(t_vector *vector)
{
  free(vector->items);
}
