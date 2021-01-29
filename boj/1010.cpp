#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 30
using namespace std;
int n, m;
int cache[MAX+1][MAX+1];
int combination(int n, int r) {
    int& tmp = cache[n][r];
    if (tmp != -1) return tmp;
    if (n == r || r == 0) 
        return 1; 
    else 
        return tmp = combination(n - 1, r - 1) + combination(n - 1, r);
}

int main() {
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            cache[i][j] = -1;

    ios::sync_with_stdio(false);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> n >> m;
        cout << combination(m, n) << endl;
    }
    return 0;
}
