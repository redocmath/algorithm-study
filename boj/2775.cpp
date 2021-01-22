#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int getCount(int k, int n) {
    if (k == 1) return (n + 1) * n / 2;
    int sum = 0;
    for (int i = 1; i <= n; i++) 
        sum += getCount(k - 1, i);
    return sum;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int k, n;
        cin >> k >> n; 
        cout << getCount(k, n) << endl;
    }
    return 0;
}
