#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"


int main() {

    struct triangle_t** triangles = NULL;
    int tr_amount = 0;
    double max_area = 0;
    double testmake = 0;

    fprintf(stdout, "Enter amount of triangles and coordinates:\n");
    triangles = read_file(stdin, triangles, &tr_amount);
    init_triangles(triangles, tr_amount);
    max_area = find_max_area(triangles, tr_amount);
    print_triangles(triangles, tr_amount);
    clear_all(triangles, tr_amount);

    return 0;
}
