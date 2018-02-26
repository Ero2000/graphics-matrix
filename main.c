#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  	screen s;
 	color c;
	clear_screen(s);
  	struct matrix *edges;
	struct matrix *test;

	edges = new_matrix(2,2);
	test = new_matrix(2,1);

	edges -> m[0][0] = 5;
	edges -> m[0][1] = 4;
	edges -> m[1][0] = 3;
	edges -> m[1][1] = 2;
	print_matrix(edges);
	
	test -> m[0][0] = 6;
	test -> m[1][0] = 3;
	print_matrix(test);
	
	matrix_mult(edges,test);
	print_matrix(test);
	
	ident(edges);
	print_matrix(edges);	

  	display(s);
}
