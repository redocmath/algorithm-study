#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    int cnt = 0;
    vector<int> d(n); for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end(), greater<int>());
    for (int i = 0; i < n; i++) {
        cnt += k / d[i]; k %= d[i];
    }
    cout << cnt;
}