#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"
#include "math.h"

int main() {

  screen s;
  color c;
  //#################  MUSIC ####################//
        c.green = 255;
        c.red = 255;
        c.blue = 255;

        int x0, y0, x1, y1;
        struct matrix *note = new_matrix(4, 0);

        //Head
        double theta = 0.0;
        double radius = 40;

        int center_x = 230;
        int center_y = 200;

        x0 = center_x + radius;
        y0 = center_y;


        while (theta < 360.0){
                x1 = radius*cos(theta) + center_x;
                y1 = radius*sin(theta) + center_y;

                add_edge(note, x0, y0, 0, x1, y1, 0);

                x0 = x1;
                y0 = y1;

                theta = theta + .0001;
        }

        //Stem

        int height = 230;

        add_edge(note, center_x + radius, center_y, 0, center_x + radius, center_y$


        //Flag

        x0 = center_x + radius;
        y0 = center_y + height;

        int flag_radius = 40;

        center_x = x0 + flag_radius;
        center_y = y0;

        while (x0 < center_x){
                x1 = flag_radius*cos(theta) + center_x;
                y1 = flag_radius*sin(theta) + center_y;

                add_edge(note, x0, y0, 0, x1, y1, 0);

                x0 = x1;
                y0 = y1;

                theta = theta + .1;
        }


        while (x0 > center_x - flag_radius){
                x1 = flag_radius*cos(theta) + center_x;
                y1 = (flag_radius-4)*sin(theta) + center_y;

                add_edge(note, x0, y0, 0, x1, y1, 0);

                x0 = x1;
                y0 = y1;

                theta = theta - .1;
        }

        draw_lines(note, s, c);
        display(s);

        free_matrix( note );
}
