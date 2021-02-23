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
        int i;
        for (i = 1; i * i <= n; i++) continue;
        cout << i - 1 << "\n";
    }
    return 0;
}
