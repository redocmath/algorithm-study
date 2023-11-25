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
#include <deque>
#include <cstring>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int w[4]; cin >> w[0] >> w[1] >> w[2] >> w[3];

        string a, b; cin >> a >> b;
        ll df = 0;
        for (int i = 0; i < 4; i++) {
            if (a[i] != b[i]) df += w[i];
        }
        cout << df << "\n";
    }
}