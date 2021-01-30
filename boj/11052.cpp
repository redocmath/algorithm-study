#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int n;
int cache[1001] = {0,};

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> P(n);

    for (int i = 0; i < n; i++) cin >> P[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cache[i] = max(cache[i], P[j - 1] + cache[i - j]);
        }
    }

    cout << cache[n];
    return 0;
}
