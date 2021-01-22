#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    long long N, distance = 1, bias = 1;
    cin >> N;

    if(N == 1) {
        cout << 1;
        return 0;
    }

    if(N < 7) {
        cout << 2;
        return 0;
    }

    while(true) {
        if (N >= 1 + bias * 6 && N <= 1 + (bias + distance + 1) * 6 ) break;
        else {
            distance += 1;
            bias += distance;
        }
    }
    cout << (distance + 2);
    return 0;
}
