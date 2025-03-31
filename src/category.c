#include "category.h"
#include <stdlib.h>

stock_list_t *new_stock_list(void) {
  stock_list_t *new = (stock_list_t*)malloc(sizeof(stock_list_t));
  new->head = NULL;
  new->count_id = 1;
  return new;
}

void add_category(stock_list_t **p) {
  category_t *new = (category_t*)malloc(sizeof(category_t));
  new->id = (*p)->count_id++;
  new->next = NULL;

  if ( (*p)->head == NULL ) {
    (*p)->head = new;
  } else {
    category_t *aux = (*p)->head;

    while (aux->next != NULL) {
      aux = aux->next;
    }
    aux->next = new;
  }
}

void free_category(stock_list_t **p) {
  while ( (*p)->head != NULL ) {
    category_t *next = (*p)->head->next;
    free( (*p)->head );
    (*p)->head = next;
  }
}

int del_category(stock_list_t **p, int id) {
  category_t *aux = (*p)->head;
  category_t *prev = NULL;
  while ( (aux != NULL) && (aux->id != id) ) {
    prev = aux;
    aux = aux->next;
  }

  if ( aux != NULL ) {
    if ( prev != NULL ) {
      prev->next = aux->next;
    } else {
      (*p)->head = aux->next;
    }
    free(aux);
    return 0;
  }
  return -1;
}

void print_categories(FILE *out, stock_list_t *p) {
  category_t *aux = p->head;
  while ( aux != NULL ) {
    fprintf(out, "%d, ", aux->id);
    aux = aux->next;
  }
  fprintf(out, "\n");
}
