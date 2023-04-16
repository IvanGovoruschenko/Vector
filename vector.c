#include "vector.h"

Vector createVector(size_t n)
{
    Vector v;
    v.data = (int *) malloc(sizeof(int) * n);
    v.size = 0;
    v.capacity = n;

    if (!v.data)
    {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return v;
}

void reserve(Vector *v, size_t newCapacity)
{
    if (newCapacity < v->size)
    {
        v->size = newCapacity;

        if (newCapacity == 0)
            v->data = NULL;
    }

    v->data = realloc(v->data, newCapacity);
    if (!v->data)
    {
        fprintf(stderr, "bad alloc");
        exit(1);
    }
    v->capacity = newCapacity;
}

void clear(Vector *v)
{
    v->size = 0;
}

void shrinkToFit(Vector *v)
{
    reserve(v, v->size);
}

void deleteVector(Vector *v)
{
    free(v->data);
}