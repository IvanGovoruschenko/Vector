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

bool isEmpty(Vector *v)
{
    return v->size == 0;
}

bool isFull(Vector *v)
{
    return v->size == v->capacity;
}

int getVectorValue(Vector *v, size_t i)
{
    return v->data[i];
}

void pushBack(Vector *v, int x)
{
    if (isFull(v))
    {
        if (isEmpty(v))
            reserve(v, 1);
        else
            reserve(v, v->capacity * 2);
    }

    v->data[v->size++] = x;
}

void popBack(Vector *v)
{
    if (isEmpty(v))
    {
        fprintf(stderr, "empty vector");
        exit(1);
    }

    v->size--;
}