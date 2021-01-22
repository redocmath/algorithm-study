#include <iostream>
#include <malloc.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = (int *)malloc(4 * n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int m = arr[0];
    for (int i = 1; i < n; i++) {
        if (m < arr[i]) {
            m = arr[i];
        }
    }
    
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (float)arr[i] / (float)m * 100.0;
    }
    
    cout << (float)(sum / (float)n);
    
    return 0;
}
