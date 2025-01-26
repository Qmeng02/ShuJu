#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Lstack{
    E element;
    struct Lstack * next;
};

