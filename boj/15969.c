//
//  main.c
//  KOC_c
//
//  Created by Coder on 2020/03/02.
//  Copyright © 2020 Coder. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// hyperparameter
int N;
int* score;

// min
int min(){
    int min = score[0];
    for (int i = 1; i < N; i++) {
        if (score[i] < min) {
            min = score[i];
        }
    }
    return min;
}

// max
int max(){
    int max = score[0];
    for (int i = 1; i < N; i++) {
        if (score[i] > max) {
            max = score[i];
        }
    }
    return max;
}

// main
int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    score = (int *)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
    }
    
    printf("%d", max() - min());
}
