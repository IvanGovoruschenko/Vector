#include <stdio.h>
#include <stdlib.h>


#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

typedef struct Vector
{
    int *data; // указатель на элементы вектора
    size_t size; // размер вектора
    size_t capacity; // вместимость вектора
} Vector;

// возвращает структуру-дескриптор вектор из n значений
Vector createVector(size_t n);

// изменяет количество памяти, выделенное под хранение элементов вектора.
void reserve(Vector *v, size_t newCapacity);

//
void clear(Vector *v);

//
void shrinkToFit(Vector *v);

//
void deleteVector(Vector *v);

#endif //VECTOR_VECTOR_H
