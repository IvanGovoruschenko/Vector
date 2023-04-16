#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// изменяет количество памяти, выделенное под хранение элементов вектора v на newCapacity
void reserve(Vector *v, size_t newCapacity);

// удаляет элементы из вектора v, но не освобождает выделенную память
void clear(Vector *v);

// освобождает память, выделенную под неиспользуемые элементы вектора v
void shrinkToFit(Vector *v);

// освобождает память, выделенную вектору v
void deleteVector(Vector *v);

// возвращает "истина", если вектор v пустой, иначе - "ложь"
bool isEmpty(Vector *v);

// возвращает "истина", если вектор v полный, иначе - "ложь"
bool isFull(Vector *v);

// возвращает i-ый элемент вектора v
int getVectorValue(Vector *v, size_t i);

// добавляет элемент x в конец вектора v. Если вектор заполнен, увеличивает количество выделенной ему памяти в
// 2 раза, используя reserve
void pushBack(Vector *v, int x);

// удаляет последний элемент из вектора v
void popBack(Vector *v);

#endif //VECTOR_VECTOR_H
