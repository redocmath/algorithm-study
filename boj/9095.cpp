#include <iostream>
#define MAX 11

using namespace std;

int mem[MAX] = {1, 2, 4, 0, };

int getCount(int n) {
    if (mem[n - 1] > 0) return mem[n - 1];
    
    int ret = 0;
    for (int i = 1; i < n; i++) {
        ret += getCount(n - i);
    }

    mem[n - 1] = ret;
    return mem[n - 1];
}

int main() {
    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        int N; cin >> N;
        cout << getCount(N) << endl;
    }

    return 0;
}
