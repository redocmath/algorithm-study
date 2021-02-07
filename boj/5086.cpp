#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    while (true) {
        int n, k; cin >> n >> k;
        if (n == 0 && k == 0) break;
        if (k % n == 0) cout << "factor\n";
        else if (n % k == 0) cout << "multiple\n";
        else cout << "neither\n";
    }
    return 0;
}
