#include "category.h"
#include <stdlib.h>

void add_category(category_t **p) {
  category_t *new = (category_t*)malloc(sizeof(category_t));
  new->id = 1;
  new->next = NULL;

  if (*p == NULL) {
    *p = new;
  } else {
    int id = 2;
    category_t *aux = *p;

    while (aux->next != NULL) {
      ++id;
      aux = aux->next;
    }
    new->id = id;
    aux->next = new;
  }
}

void free_category(category_t **p) {
  while ( *p != NULL ) {
    category_t *next = (*p)->next;
    free(*p);
    *p = next;
  }
}
