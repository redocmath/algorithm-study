#include<iostream>
using namespace std;

int find(int val, int a[10]) {
    for (int i = 0; i < 10; i++) {
        if (a[i] == val) {
            return 1;
        }
    }
    return 0;
}

int main(void){
    int a[10] = {0, };
    int count = 0;
    
    for (int i = 0; i < 10; i++) {
        cin >> a[i];
        a[i] = a[i] % 42;
    }
    
    for (int i = 0; i < 42; i++) {
        if (find(i, a) == 1) {
            count += 1;
        }
    }
    
    cout << count;
    return 0;
}
