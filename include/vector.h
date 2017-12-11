/*
** vector.h for vector in /home/arbona/libs/vector
**
** Made by Thomas ARBONA
** Login   <thomas.arbona@epitech.eu>
**
** Staed on  Mon Feb 27 19:44:11 2017 Thomas ARBONA
** Last update Mon Mar 13 23:14:36 2017 Thomas ARBONA
*/
#ifndef VECTOR_H_
# define VECTOR_H_

typedef struct Vector {
  void **items;
  int capacity;
  int size;
}	Vector;

int	vector_create(Vector*);
void vector_destroy(Vector*);
int	vector_resize(Vector*, int);
int	vector_getsize(const Vector*);
void vector_delete(Vector*, int);
void vector_so(Vector*, int (*)(void*, void*));
void _vector_set(Vector*, int, void*);
void *_vector_get(const Vector*, int);
void _vector_push(Vector*, void*);

# define VECTOR_INIT_CAPACITY	8

# define vector_set(v, i, item)	_vector_set(v, i, (void*)item)
# define vector_get(v, i, type)	(type*)_vector_get(v, i)
# define vector_push(v, item)	_vector_push(v, (void*)item)
# define vector_foreach(v, type, func) for (int it = 0; it < v.size; it += 1) func((type *)v.items[it]);

#endif /* !VECTOR_H_ */
