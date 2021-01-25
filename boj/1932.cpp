#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 500

using namespace std;

int N;
int datas[MAX_N][MAX_N];
int caches[MAX_N][MAX_N];

// position system
//
// (0,0)--------->(INF, 0)
// |
// |
// |
// |
// |
// |
// V
// (0, INF)

int getMaximum(int x, int y) {
    int& tmp = caches[y][x];
    if (tmp != -1) return tmp;
    return tmp = max(datas[y][x] + getMaximum(x + 1, y + 1), datas[y][x] + getMaximum(x, y + 1));
}

int main() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j < MAX_N; j++) {
            datas[i][j] = -1;
            caches[i][j] = -1;
        }
    }

    // ios::sync_with_stdio(false);
    cin >> N;

//  scaffolding 1: worked.
//  for (int i = 0; i < N; i++) {
//      for (int j = 0; j <= i; j++) {
//          if (i == j) datas[i][j] = 1;
//          else datas[i][j] = 0;
//      }
//  }
    
//  real
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> datas[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        caches[N - 1][i] = datas[N - 1][i];
    }

    cout << getMaximum(0, 0);
    
    return 0;
}
