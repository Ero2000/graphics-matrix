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

	struct matrix *coolio;

	coolio = new_matrix(4,10);
	int x0,y0,x1,y1,a,b,t;
	c.red = 255;
	c.green = 0;
	c.blue = 1;

	for(t = 0; t < 250; t++){
		c.red -= t;
		c.green += t;
		if(c.green >= 255){
			c.green = 0;
		}
		x0 = t;
		y0 = 0;
		x1 = 5 + t;
		y1 = 50;	
		a = 5;
		b = 50;
		while (x0 < 250){
			add_edge(coolio, x0, y0, 0, x1, y1, 0);
			x0 = x1;
			y0 = y1;
			x1 += a;
			y1 += b;
			a += 5;
			b -= 5;
		}
		draw_lines(coolio,s,c);
		free_matrix(coolio);
		coolio = new_matrix(4,10);
	}


  	display(s);
}
