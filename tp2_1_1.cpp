#include <stdio.h>
#include <stdlib.h>

#define N 20

int main()
{    
    int i;
    int vt[N];
    

    for(i = 0;i<N; i++)
    {
        vt[i]=1+rand()%100;
        printf("\n %d ", vt[i]);
    }

return 0;
}    