#include <iostream>
using namespace std;

int main() {
    int N, X, temp;
    cin >> N >> X;
    
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp < X) {
            cout << temp << " ";
        }
    }
}