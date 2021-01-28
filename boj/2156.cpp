#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, ret;
int amount[10003];
int cache[10003];

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 10000; i++) cache[i] = -1;

    cin >> N;
    for (int i = 3; i < N + 3; i++) {
        int& tmp = amount[i];
        cin >> tmp;
    }

    for (int i = 3; i < N + 3; i++) {
        cache[i] = max(cache[i-3] + amount[i-1] + amount[i], cache[i-2] + amount[i]);
        cache[i] = max(cache[i-1], cache[i]);
        ret = max(ret, cache[i]);
    }

    cout << ret;

    return 0;
}
