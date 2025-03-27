#include "category.h"
#include <stdlib.h>

void add_category(category_t **p) {
  category_t *new = (category_t*)malloc(sizeof(category_t));
  new->id = 1;
  new->next = NULL;

  if (*p == NULL) {
    *p = new;
  } else {
    category_t *aux = *p;

    while (aux->next != NULL) { aux = aux->next; }
    aux->next = new;
  }
}
