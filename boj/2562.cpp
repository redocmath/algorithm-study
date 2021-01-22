#include <iostream>
#include <malloc.h>
using namespace std;

int arr[9];

int biggiest() {
    int temp = 0;
    
    for (int i = 1; i < 9; i++) {
        if (arr[i] > arr[temp]) {
            temp = i;
        }
    }
    
    return temp;
}

int main()
{
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }
    int result = biggiest();
    cout << arr[result] << endl << result + 1;
    
    return 0;
}
