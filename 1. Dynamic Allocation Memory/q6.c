#include <stdlib.h>
int main()
{
    int *p, *q;
    int *r;
    int *s;
    
    p = (int*) malloc(sizeof(int));
    r = p; 
    *p = 5;
    p = (int*) malloc(sizeof(int));
    q = p;
    s = r;
    *q = *s + 1;
    *r = *p * 2;
    
    // (A)
    free(r); r = NULL;
    free(q); q = NULL;
    // (B)
}