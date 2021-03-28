#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, k;

int dis[100001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;

    fill(dis, dis+100001, -1);

    dis[n] = 0;
    queue<int> Q;
    Q.push(n);

    while (dis[k] == -1) {
        int cur = Q.front(); Q.pop();
        for (int nxt: {cur-1, cur+1, cur*2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (dis[nxt] != -1) continue;
            dis[nxt] = dis[cur]+1;
            Q.push(nxt);
        }
    }

    cout << dis[k];
    return 0;
}
