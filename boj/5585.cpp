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
    int n; cin >> n; n = 1000 - n;
    int cnt = 0;
    const int d[5] = {500, 100, 50, 10, 5, 1};
    for (int i = 0; i < 5; i++) {
        cnt += n / d[i]; n %= d[i];
    }
    cout << cnt;
}