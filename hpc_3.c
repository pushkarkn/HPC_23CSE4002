#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 15

int main(){

int A[N];

srand(42);
for(int i=0; i<N; i++){

    A[i]= rand()% 500;
}
printf("Array Elements: \n");
for(int i= 0; i<N; i++){
printf("A[%d]= %d\n", i, A[i]);
}
int max= A[0];
int id= 0;

#pragma omp parallel for 
for(int i= 1; i< N; i++){
if(A[i]>max){
    #pragma critical
    {
        if (A[i]>max){
            max= A[i];
            id= i;
        }
    }
}
}
printf("Largest Value: %d\n", max);
printf("At Index:      %d\n", id);

    return 0;
}