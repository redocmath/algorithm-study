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

int a[51][51], b[51][51];

void convert(int x, int y) {
    for (int i = x; i < x+3; i++)
        for (int j = y; j < y+3; j++)
            a[i][j] = 1-a[i][j];
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            scanf("%1d", &a[i][j]);

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            scanf("%1d", &b[i][j]);
    
    int res = 0;
    for (int i = 0; i <= n-3; i++)
        for (int j = 0; j <= m-3; j++) {
            if (a[i][j] == b[i][j]) continue;
            convert(i, j);
            res++;
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != b[i][j]) {
                cout << "-1";
                return 0;
            }
    
    cout << res;
    return 0;
}