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
int mx = -1;
int a[50][50];

// Simple Implimention
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int lcmax = 0;
            for (int k = max(0, i-m); k <= min(n-1, i+m); k++)
                lcmax += a[k][j];
            for (int k = max(0, j-m); k <= min(n-1, j+m); k++)
                lcmax += a[i][k];
            lcmax -= a[i][j];
            // cout << "cross i:" << i << ",j:" << j << ", lcmax:" << lcmax << "\n";
            mx = max(lcmax, mx);

            lcmax = 0;
            for (int k = 0; k <= 2*m; k++) {
                if (0 <= i-m+k && 0 <= j-m+k && n-1 >= i-m+k && n-1 >= j-m+k)
                    lcmax += a[i-m+k][j-m+k];
            }
            for (int k = 0; k <= 2*m; k++) {
                if (0 <= i-m+k && 0 <= j+m-k && n-1 >= i-m+k && n-1 >= j+m-k)
                    lcmax += a[i-m+k][j+m-k];
            }
            lcmax -= a[i][j];
            // cout << "closs i:" << i << ",j:" << j << ", lcmax:" << lcmax << "\n";
            mx = max(lcmax, mx);
        }
    }

    cout << mx;
}