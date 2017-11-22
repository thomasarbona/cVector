/*
** vector.h for vector in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Started on  Mon Feb 27 19:44:11 2017 Thomas ARBONA
** Last update Mon Mar 13 23:14:36 2017 Thomas ARBONA
*/
#ifndef VECTOR_H_
# define VECTOR_H_

typedef struct {
  void **items;
  int capacity;
  int size;
}	vector_t;

int	vector_create(vector_t*);
void	vector_destroy(vector_t*);
int	vector_resize(vector_t*, int);
int	vector_getsize(vector_t*);
void	vector_delete(vector_t*, int);
void	vector_foreach(vector_t*, void (*)(void*, int));
void	vector_sort(vector_t*, int (*)(void*, void*));
void	_vector_set(vector_t*, int, void*);
void	*_vector_get(vector_t*, int);
void	_vector_push(vector_t*, void*);

# define VECTOR_INIT_CAPACITY	8

# define vector_set(v, i, item)	_vector_set(v, i, (void*)item)
# define vector_get(v, i, type)	(type*)_vector_get(v, i)
# define vector_push(v, item)	_vector_push(v, (void*)item)

#endif /* !VECTOR_H_ */
