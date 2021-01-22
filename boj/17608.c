#include <stdio.h>
#include <stdlib.h>

// var
int* array_stick;
int N;
int count = 0;

// main
int main(){
    scanf("%d", &N);
    
    array_stick = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &array_stick[i]);
    }
    
    int max_h = array_stick[N - 1];
    count++;

    for (int i = N - 2; i >= 0; i--) {
        if (array_stick[i] > max_h) {
            max_h = array_stick[i];
            count++;
        }
    }

    printf("%d", count);
}
