#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
    int i, num = 0;

    srand( time(NULL) );   // seed값
    for ( i=0; i<100; i++ )
    {
       printf("%d ", (rand()%100) + 1 );
    }
    return 0;
 }