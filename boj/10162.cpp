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

    ll t; cin >> t;
    if (t % 10 != 0) cout << "-1";
    else {
        int a = t / 300;
        t %= 300;
        int b = t / 60;
        t %= 60;
        int c = t / 10;
        cout << a << " " << b << " " << c;
    }
}