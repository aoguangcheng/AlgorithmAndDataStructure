#include<stdio.h>

int main()
{
    int A[6];
    for(int i = 0; i < 6; i++)
    {
        scanf("%d", &A[i]);
    }
    int n = 0;
    if(A[0] > A[4])
        n = n + A[4];
    else
        n = n + A[0];
    if(A[1] > A[5])
         n =n + A[5];
    else
        n = n + A[1];
    if(A[2] > A[3])
        n = n + A[3];
    else
        n = n + A[2];
    printf("%d", n);
    return 0;
}