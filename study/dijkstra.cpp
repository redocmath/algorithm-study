#include <bits/stdc++.h>
#include <queue>
#define MAX_V 20000
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int vcount, ecount, start, dest;

void solve() {
    vector<P> adj[MAX_V];
    for (int i = 0; i < ecount; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u-1].push_back(P(v-1, w));
    }

    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    bool visited[MAX_V] = {0};
    priority_queue<P, vector<P>, greater<P>> PQ;
    
    start--;
    dist[start] = 0;
    PQ.push(P(0, start));

    while(!PQ.empty()){ 
        int curr;
        do{
            curr = PQ.top().second;
            PQ.pop();
        }while(!PQ.empty() && visited[curr]); 
        if(visited[curr]) break;
 
        visited[curr] = true;
        for(auto &p: adj[curr]){
            int next = p.first, d = p.second;
            if(dist[next] > dist[curr] + d){
                dist[next] = dist[curr] + d;
                PQ.push(P(dist[next], next));
            }
        }
    }

    cout << dist[dest-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> vcount >> ecount >> start >> dest;
    solve();
    return 0;
}
