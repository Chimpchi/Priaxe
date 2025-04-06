#pragma once

#include <defines.h>

typedef enum priaxe_vector_type
{
    VECTOR2, VECTOR3
} priaxe_vector_type;

typedef struct priaxe_vector2
{
    f32 x, y;
} priaxe_vector2;

typedef struct priaxe_vector2_int
{
    i32 x, y;
} priaxe_vector2_int;

typedef struct priaxe_vector3
{
    f32 x, y, z;
} priaxe_vector3;

typedef struct priaxe_vector3_int
{
    i32 x, y, z;
} priaxe_vector3;

typedef struct priaxe_generic_vector
{
    priaxe_vector_type type;
    union
    {
        priaxe_vector2 vec2;
        priaxe_vector2_int vec2i;
        priaxe_vector3 vec3;
        priaxe_vector3_int vec3i;
    } priaxe_generic_vector;
    
};

void priaxe_vector_add(const priaxe_generic_vector* lhs, const priaxe_generic_vector* rhs);
void priaxe_vector_subtract(const priaxe_generic_vector* lhs, const priaxe_generic_vector* rhs);
void priaxe_vector_multiply(const priaxe_generic_vector* vector, f32 scalar);
void priaxe_vector_divide(const priaxe_generic_vector* vector, f32 scalar);