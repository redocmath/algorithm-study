#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int table[30][30] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    table[0][0] = 1;

    for (int i = 1; i < 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) table[i][j] = 1;
            else table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }


    int R, C, W;
    cin >> R >> C >> W;

    int sum = 0;
    for (int i = R-1; i < R+W-1; i++) {
        for (int j = C-1; j <= C - 1 + i - (R-1); j++) sum += table[i][j];
    }

    cout << sum;
    
    return 0;
}
