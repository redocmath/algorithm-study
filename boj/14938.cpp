#include <bits/stdc++.h>
#define MAX_V 1000
#define INF 1000000000
typedef long long ll;
using namespace std;
typedef pair<int, int> P;

void solve() {
    int V, E, M, K;
    vector<P> adj[MAX_V];
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u-1].push_back(P(v-1, w));
    }

    cin >> K >> M;
    K--; M--;
 
    int dist[MAX_V];
    fill(dist, dist+MAX_V, INF);
    bool visited[MAX_V] = {0};
    priority_queue<P, vector<P>, greater<P>> PQ;
 
    dist[K] = 0; 
    PQ.push(P(0, K)); 
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
 
    if (dist[M] == INF) cout << "INF";
    else cout << dist[M];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
