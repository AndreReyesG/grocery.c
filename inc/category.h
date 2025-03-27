#pragma once

typedef struct Category {
  struct Category *next;
  char name[20];
  int numprods;
  int id;
} category_t;

void add_category(category_t **p);
