#pragma once
#include <stdio.h>

typedef struct Category {
  struct Category *next;
  char name[20];
  int numprods;
  int id;
} category_t;

void add_category(category_t **p);
void free_category(category_t **p);
int del_category(category_t **p, int id);
void print_categories(FILE *out, category_t *p);
