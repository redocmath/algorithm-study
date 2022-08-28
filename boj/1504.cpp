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

int n, e;
vector<vector<P>> graph;
vector<int> cost;

int solve(int be, int en) {
    cost.resize(n+1);
    fill(cost.begin(), cost.end(), INT32_MAX);
    cost[be] = 0;
    priority_queue<int> PQ; PQ.push(be);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> e;

    graph.resize(n+1);
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    int v1, v2; cin >> v1 >> v2;
    cout << solve(v1, v2);
}