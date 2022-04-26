#include<stdio.h>
#include <stdlib.h>

#define N 20

int main()
{
    int i;
    int vt[N];
    int *Pvt;

    Pvt = vt;

    for(i = 0;i<N; i++)
    {
        *Pvt = rand () % 100 +1;
        printf("\n %d", *Pvt);
        Pvt++;
    }
}

