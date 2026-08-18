#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10

int main()
{
    float A[N];
    float sum= 0.0f;
    float avg= 0.0f;


for (int i= 0; i<N; i++)
{
    A[i]= (float)(i+1)*1.5f;

}
#pragma omp parallel for reduction(+:sum)
for(int i= 0; i<N; i++)
{
    sum+= A[i];
}
avg= sum/N;

printf("Array Elements:\n");
    for (int i = 0; i < N; i++) {
        printf("A[%d] = %.2f\n", i, A[i]);
    }
printf("sum: %f\n", sum);
printf("average: %f\n", avg);

return 0;
}