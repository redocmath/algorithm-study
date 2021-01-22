#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;

double average(int* arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += arr[i];
    return (double)sum / (double)n;
}

int main(){
    int c, n, count;
    cin >> c;

    for (int i = 0; i < c; i++) {
        count = 0;
        cin >> n;
        int* arr = (int *)malloc(4 * n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        double aver = average(arr, n);
        
        for (int j = 0; j < n; j++) {
            if (arr[j] > aver) count++;
        }
        printf("%.3f%\n", (double)((double)count / (double)n) * 100);
    }
    
    return 0;
}