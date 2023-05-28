#include <stdlib.h>
#include <stdio.h>


void swap(int *a, int *b) // example of function call: swap(&x, &y);
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}


//void test_func()
//{
//    return 1;
//}


int main()
{
//    printf("%d\n", test_func());

    return 0;
}