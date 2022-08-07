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

int n, m;
vector<int> a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    b.resize(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    if (a[0] < b[0]) {
        cout << "-1"; return 0;
    }
    
    int res = 0;
    while (b.size()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] >= b[j]) {
                    b.erase(b.begin()+j);
                    m--;
                    break;
                }
            }
        }
        res++;
    }
    cout << res;
}