#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  print_matrix(edges);
  ident(edges);
  print_matrix(edges);

  struct matrix *test;
  test = new_matrix(4, 3);
  test -> test[0][0] = 25;

  matrix_mult(edges, test);
  print_matrix(test);
  /*
  draw_lines(edges, s, c);
  display(s);
  free_matrix( edges );
  */
}
