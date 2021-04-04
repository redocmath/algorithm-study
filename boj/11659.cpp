#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a[i+1] = a[i] + tmp;
    }

    while (m--) {
        int i, j; cin >> i >> j;
        cout << a[j] - a[i-1] << "\n";
    }
}