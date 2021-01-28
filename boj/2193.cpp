#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 90
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int n; cin >> n;
    long long cache[MAX + 1] = {0, };
    cache[0] = 0;
    cache[1] = 1;

    for (int i = 3; i <= n; i++) {
        cache[i] = cache[i - 1] + cache[i - 2];
    }

    cout << cache[n] << endl;
    return 0;
}
