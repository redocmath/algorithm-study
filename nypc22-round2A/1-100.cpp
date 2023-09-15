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
#include <map>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int n;
vector<int> a;
vector<int> color[1000001];
vector<int> info;
vector<int> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    a.resize(n); info.resize(n); ans.resize(n);
    for (int i = 0; i<n; i++) {
        cin >> a[i];
        color[a[i]].push_back(i);
        info[i] = color[a[i]].size();
    }
    for (int i = 0; i < n; i++) {
        if (info[i] == color[a[i]].size()) info[i] = n;
        else info[i] = color[a[i]][info[i]];
    }

    int mx = n;
    for (int i = n-1; i >= 0; i--) {
        mx = min(mx, info[i]);
        ans[i] = mx;
    }

    // for (int i = 0; i < n; i++) cout << ans[i] << " ";

    mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, ans[i]-i);
    }
    cout << mx;
}