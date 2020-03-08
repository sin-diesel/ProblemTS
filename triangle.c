//
// Created by Stas Sidelnikov on 2020-02-25.
//
#include "triangle.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


double find_max_area(struct triangle_t** triangles, int tr_amount) {

    assert(triangles);

    int i;
    double max_area;

    max_area = 0;

    for (i = 0; i < tr_amount; ++i) {

        if (triangles[i]->area > max_area) {

            max_area = triangles[i]->area;

        }
    }

    return max_area;
}

double find_sum_area(struct triangle_t** triangles, int tr_amount) {

    assert(triangles);

    int i;
    double sum_area;

    sum_area = 0;

    for (i = 0; i < tr_amount; ++i) {

        sum_area += triangles[i]->area;
    }

    return sum_area;
}

struct triangle_t** read_file(FILE* file, struct triangle_t** data, int *amount) {

    const int max_coord = 3;
    int i;
    int j;


    *amount = (int) getchar();
    *amount = *amount - '0';
    //assert(fscanf(file, "%d\n", amount) == 1);

    fprintf(stdout, "%d\n", *amount);

    data = (struct triangle_t**) calloc(*amount, sizeof(struct triangle_t*));
    assert(data);
    for (i = 0; i < *amount; ++i) {
        data[i] = (struct triangle_t*) calloc(1, sizeof(struct triangle_t));
        assert(data[i]);
    }

    for (i = 0; i < *amount; ++i) {

        assert(scanf("%lg %lg %lg %lg %lg %lg", &data[i]->vector1.x, &data[i]->vector1.y,
                                                &data[i]->vector2.x, &data[i]->vector2.y,
                                                &data[i]->vector3.x, &data[i]->vector3.y) == 6);

        data[i]->vector1.z = 0;
        data[i]->vector2.z = 0;
        data[i]->vector3.z = 0;

        fprintf(stdout, "%lg %lg\n", data[i]->vector1.x, data[i]->vector1.y);

        fprintf(stdout, "%lg %lg\n", data[i]->vector2.x, data[i]->vector2.y);

        fprintf(stdout, "%lg %lg\n", data[i]->vector3.x, data[i]->vector3.y);

    }

    return data;
}

struct vector_t* count_cross_product(struct vector_t* vec1, struct vector_t* vec2) {

    assert(vec1);
    assert(vec2);

    struct vector_t* vec3 = (struct vector_t*) calloc(1, sizeof(struct vector_t));
    assert(vec3);

    vec3->x = vec1->y * vec2->z - vec1->z * vec2->y;
    vec3->y = -1 * (vec1->x * vec2->z - vec1->z * vec2->x);
    vec3->z = vec1->x * vec2->y - vec1->y * vec2->x;

    return vec3;
}

double count_len(struct vector_t* vec) {

    assert(vec);

    return sqrt(vec->x * vec->x + vec->y * vec->y + vec->z * vec->z);
}

void init_triangles(struct triangle_t** data, int tr_amount) {

    int i;
    struct vector_t* cross_product = NULL;

    for (i = 0; i < tr_amount; ++i) {


        data[i]->vector2.x = data[i]->vector2.x - data[i]->vector1.x;
        data[i]->vector2.y = data[i]->vector2.y - data[i]->vector1.y;
        data[i]->vector2.z = data[i]->vector2.z - data[i]->vector1.z;

        data[i]->vector3.x = data[i]->vector3.x - data[i]->vector1.x;
        data[i]->vector3.y = data[i]->vector3.y - data[i]->vector1.y;
        data[i]->vector3.z = data[i]->vector3.z - data[i]->vector1.z;

        data[i]->vector1.len = count_len(&data[i]->vector1);
        data[i]->vector2.len = count_len(&data[i]->vector2);
        data[i]->vector3.len = count_len(&data[i]->vector3);

        cross_product = count_cross_product(&data[i]->vector2, &data[i]->vector3);
        data[i]->area = 0.5 * count_len(cross_product);
        free(cross_product);

    }
    return;
}

void clear_all(struct triangle_t** triangles, int tr_amount) {

    for(int i = 0; i < tr_amount; ++i) {

        free(triangles[i]);

    }

    free(triangles);
}

void print_triangles(struct triangle_t** triangles, int amount) {

    int i;

    assert(triangles);

    for (i = 0; i < amount; ++i) {

        fprintf(stdout, "Triangle %d: vector1 coordinates: (%lg, %lg, %lg), vector1 length: %lg\n", i, triangles[i]->vector1.x,
                triangles[i]->vector1.y, triangles[i]->vector1.z, triangles[i]->vector1.len);
        fprintf(stdout, "Triangle %d: vector2 coordinates: (%lg, %lg, %lg), vector2 length: %lg\n", i, triangles[i]->vector2.x,
                triangles[i]->vector2.y, triangles[i]->vector2.z, triangles[i]->vector2.len);
        fprintf(stdout, "Triangle %d: vector3 coordinates: (%lg, %lg, %lg), vector3 length: %lg\n", i, triangles[i]->vector3.x,
                triangles[i]->vector3.y, triangles[i]->vector3.z, triangles[i]->vector3.len);
        fprintf(stdout, "Triangle area: %lg\n", triangles[i]->area);

    }
    return;
}

