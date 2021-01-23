#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long mem[91] = {0, 1, };

long getFibonacci(long n) {
    if (n <= 1 || mem[n] != -1) return mem[n];
    mem[n] = getFibonacci(n - 1) + getFibonacci(n - 2);
    return mem[n];
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 2; i < 91; i++) mem[i] = -1;

    long n; cin >> n;

    cout << getFibonacci(n);
    return 0;
}
