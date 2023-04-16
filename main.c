#include <stdio.h>
#include <stdint.h>

#include "vector.h"

int main()
{
    Vector v = createVector(0);

    printf("%d ", v.data[0]);
    printf("%d ", v.data[1]);
    printf("%d ", v.data[2]);

    reserve(&v, 2);

    printf("%d ", v.data[0]);
    printf("%d ", v.data[1]);
    printf("%d ", v.data[2]);

    return 0;
}
