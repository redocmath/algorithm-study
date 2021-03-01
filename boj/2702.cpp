#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
    ll gc = gcd(a, b);
    return gc * (a / gc) * (b / gc);
}

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (a > b) {
            cout << lcm(a, b) << " " << gcd(a, b) << "\n";
        } else {
            cout << lcm(b, a) << " " << gcd(b, a) << "\n";
        }
    }
    return 0;
}
