#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;
int cache[41][2];

int fibo_0(int n) {
    int& tmp = cache[n][0];
    if (tmp != -1) {
        return tmp;
    }
    if (n == 1) return 0;
    if (n == 0) {
        tmp = 1;
        return tmp;
    }

    return tmp = fibo_0(n - 1) + fibo_0(n - 2);
}

int fibo_1(int n) {
    int& tmp = cache[n][1];
    if (tmp != -1) {
        return tmp;
    }
    if (n == 0) return 0;
    if (n == 1) {
        tmp = 1;
        return tmp;
    }

    return tmp = fibo_1(n - 1) + fibo_1(n - 2);
}

int main() {
    for (int i = 0; i < 41; i++) {
        cache[i][0] = -1;
        cache[i][1] = -1;
    }

    ios::sync_with_stdio(false);
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << fibo_0(N) << " " << fibo_1(N)<< endl;
    }
    return 0;
}
