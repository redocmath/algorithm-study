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
    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n+1; i++) {
        int tmp; cin >> tmp;
        a[i] = a[i-1] + tmp;
    }

    while (m--) {
        int i, j; cin >> i >> j;
        if (i < 2) cout << a[j-1] << endl;
        else cout << a[j-1] - a[i-2] << endl;
    }
}