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

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        PQ.push(t);
    }

    int res = 0;
    for (int i = 0; i < n-1; i++) {
        int a = PQ.top(); PQ.pop(); int b = PQ.top(); PQ.pop();
        PQ.push(a+b);
        res += a+b;
    }
    cout << res;
}