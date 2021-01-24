#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000001
using namespace std;

int N;
int cache[MAX];

int main() {
    for (int i = 0; i < MAX; i++) {
        cache[i] = -1;
    }

    cache[0] = 0; cache[1] = 1; cache[2] = 2;

    ios::sync_with_stdio(false);
    cin >> N;

    // bottom-up (top down DP approach Stack Overflow)
    for (int i = 3; i < N + 1; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;
    }

    cout << cache[N];
    return 0;
}
