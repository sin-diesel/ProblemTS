#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "triangle.h"


int main() {

    struct triangle_t** triangles = NULL;
    int tr_amount = 0;
    double sum_area = 0;

    triangles = read_file("in.txt", "r", triangles, &tr_amount);
    init_triangles(triangles, tr_amount);
    find_sum_area(triangles, tr_amount);
    //print_triangles(triangles, tr_amount);

    return 0;
}