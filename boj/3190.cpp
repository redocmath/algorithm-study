#include <bits/stdc++.h>
#define L -1
#define D 1
#define EAST 1
#define WEST 3
#define SOUTH 2
#define NORTH 4
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, k, l;
bool apple[100][100] = {0,};
bool issnake[100][100] = {0,};
list<P> snake;
queue<P> action;

void solve() {
    // init
    issnake[0][0] = 1;
    snake.push_front({0, 0});

    int t = 0, dir = EAST;
    P todo = action.front(); action.pop();

    P head = snake.front();
    while (1) {
//        cout << t << "-" << dir << "----------\n";
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j < n; j++)
//                cout << (snake.front().first == i && snake.front().second == j?2:issnake[i][j]);
//            cout << "\n";
//        }

        head = snake.front();
        if (todo.first == t) {
            switch (dir) {
                case EAST:
                    dir = (todo.second == L ? NORTH: SOUTH);
                    break;
                case SOUTH:
                    dir = (todo.second == L ? EAST : WEST);
                    break;
                case WEST:
                    dir = (todo.second == L ? SOUTH: NORTH);
                    break;
                case NORTH:
                    dir = (todo.second == L ? WEST: EAST);
                    break;
            }
            if (action.empty()) todo = {-1, D};
            else {
                todo = action.front();
                action.pop();
            }
        }

        bool dead = 0;
        switch (dir) {
            case EAST:
                if (head.second+1 >= n) {dead = 1; break;}
                if (issnake[head.first][head.second+1]) dead = 1;
                issnake[head.first][head.second+1] = 1;
                snake.push_front({head.first, head.second+1});
                break;
            case SOUTH:
                if (head.first+1 >= n) {dead = 1; break;}
                if (issnake[head.first+1][head.second]) dead = 1;
                issnake[head.first+1][head.second] = 1;
                snake.push_front({head.first+1, head.second});
                break;
            case WEST:
                if (head.second-1 < 0) {dead = 1; break;}
                if (issnake[head.first][head.second-1]) dead = 1;
                issnake[head.first][head.second-1] = 1;
                snake.push_front({head.first, head.second-1});
                break;
            case NORTH:
                if (head.first-1 < 0) {dead = 1; break;}
                if (issnake[head.first-1][head.second]) dead = 1;
                issnake[head.first-1][head.second] = 1;
                snake.push_front({head.first-1, head.second});
                break;
        }
        if (dead) break;
        head = snake.front();
        if (apple[head.first][head.second]) {t++; apple[head.first][head.second]=0; continue;}
        issnake[snake.back().first][snake.back().second] = 0;
        snake.pop_back();
        t++;

    }
    cout << ++t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int v, h; cin >> v >> h;
        v--; h--;
        apple[v][h] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int a; char s; cin >> a >> s;
        action.push({a, (s == 'D' ? D : L)});
    }
    solve();
    return 0;
}
