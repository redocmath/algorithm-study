#include <iostream>
#include <malloc.h>
using namespace std;

int N;
int* arr;

int biggiest() {
    int temp = arr[0];
    
    for (int i = 1; i < N; i++) {
        if (arr[i] > temp) {
            temp = arr[i];
        }
    }
    
    return temp;
}

int smallest() {
    int temp = arr[0];
    
    for (int i = 1; i < N; i++) {
        if (arr[i] < temp) {
            temp = arr[i];
        }
    }
    
    return temp;
}

int main()
{
    cin >> N;
    
    arr = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    cout << smallest() << " " << biggiest();
    
    return 0;
}