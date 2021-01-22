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


// macro
#define SUB(a, b) (a > b ? a-b : b-a)


typedef struct _dot{
    int pos;
    int color;
} Dot;

// dot info
Dot* dot;

// hyperparameter
int N;

// current status
Dot current;
int distance = 0;


// function
int nearIndex(int index){
    int* list = (int *)malloc(sizeof(int) * N);
    
    int index_list = 0;
    
    for (int i = 0; i < N; i++) {
        if (dot[i].color == dot[index].color && i != index) {
            list[index_list] = i;
            index_list++;
        }
    }
    list = (int *)realloc(list, sizeof(int) * index_list + 1);
    
    if (index_list == 0) return -1;
    
    int min = list[0];
    
    for (int i = 1; i < index_list; i++) {
        if (SUB(dot[list[i]].pos, dot[index].pos) < SUB(dot[min].pos, dot[index].pos)) {
            min = list[i];
        }
    }
    return min;
}

// main
int main(int argc, const char * argv[]) {
    scanf("%d", &N);
    
    dot = (Dot *)malloc(sizeof(Dot) * N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &dot[i].pos, &dot[i].color);
    }
    
    for (int i = 0; i < N; i++) {
        int index = nearIndex(i);
        if (index != -1) {
            distance += SUB(dot[index].pos, dot[i].pos);
        }
    }
    printf("%d", distance);
}
