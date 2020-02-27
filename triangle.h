#ifndef PROBLEMTS_TRIANGLE_H
#define PROBLEMTS_TRIANGLE_H


struct vector_t {

    double x;
    double y;
    double z;

    double len;
};

struct triangle_t {

    struct vector_t vector1;
    struct vector_t vector2;
    struct vector_t vector3;

    double area;
};

double find_sum_area(struct triangle_t** triangles, int tr_amount);

double find_max_area(struct triangle_t** triangles, int tr_amount);

struct triangle_t** read_file(const char *name, const char *type, struct triangle_t** data, int *amount);

struct vector_t* count_cross_product(struct vector_t* vec1, struct vector_t* vec2);

double count_len(struct vector_t* vec);

void init_triangles(struct triangle_t** data, int tr_amount);

void print_triangles(struct triangle_t** triangles, int amount);

#endif //PROBLEMTS_TRIANGLE_H
