#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "vector.h"

void test_pushBack_emptyVector()
{
    Vector v = createVector(0);

    pushBack(&v, 228);
    assert(v.size == 1 && v.capacity == 1 && getVectorValue(&v, 0) == 228);
}

void test_pushBack_fullVector()
{
    Vector v = createVector(1);
    *v.data = 1337;
    v.size = 1;

    pushBack(&v, 228);
    assert(v.size == 2 && getVectorValue(&v, 0) == 1337 && getVectorValue(&v, 1) == 228);

    pushBack(&v, 1488);
    assert(v.size == 3 && v.capacity == 4 && getVectorValue(&v, 0) == 1337 &&
           getVectorValue(&v, 1) == 228 && getVectorValue(&v, 2) == 1488);
}

void test_popBack_notEmptyVector()
{
    Vector v = createVector(0);

    pushBack(&v, 10);
    assert(v.size == 1);

    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test_atVector_notEmptyVector()
{
    Vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(atVector(&v, 0) == &v.data[0]);
    assert(atVector(&v, 1) == &v.data[1]);
}

void test_atVector_requestToLastElement()
{
    Vector v = createVector(3);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);

    assert(atVector(&v, 2) == &v.data[2]);
}

void test_back_oneElementInVector()
{
    Vector v = createVector(1);
    pushBack(&v, 1);

    assert(back(&v) == &v.data[v.size - 1]);
}

void test_front_oneElementInVector()
{
    Vector v = createVector(1);
    pushBack(&v, 1);

    assert(front(&v) == &v.data[0]);
}


void test()
{
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

int main()
{
    test();

    return 0;
}
