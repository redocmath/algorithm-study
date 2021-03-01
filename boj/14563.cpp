#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;

        ll factor = 0;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                factor += i;
            }
        }
        if (factor > n) cout << "Abundant\n";
        if (factor == n) cout << "Perfect\n";
        if (factor < n) cout << "Deficient\n";
    }
    return 0;
}
