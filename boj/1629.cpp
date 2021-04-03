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

ll a, b, c;
int result = 0;

ll pow(ll x, ll m) {
    if (m == 0)
        return 1;

    else if (m == 1)
        return x;

    if (m % 2 > 0)
        return pow(x, m - 1)*x;

    ll half = pow(x, m / 2);
    half %= c;
    return (half * half) % c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> a >> b >> c;
    cout << pow(a, b) % c;
}