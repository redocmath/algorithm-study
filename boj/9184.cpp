#include <iostream>
#include <vector>
#include <string>
#define MAX 100

using namespace std;


int A, B, C;
int ret[MAX][MAX][MAX];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) return 1;
    if (ret[a-1][b-1][c-1] > 0) return ret[a-1][b-1][c-1];

    if (a > 20 || b > 20 || c > 20) {
        ret[19][19][19] = w(20, 20, 20); return ret[19][19][19];
    }

    if (a < b && b < c) {
        ret[a-1][b-1][c-1] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        return ret[a-1][b-1][c-1];
    }

    ret[a-1][b-1][c-1] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    return ret[a-1][b-1][c-1];
}

int main() {
    for(int i = 0; i < MAX; i++) for(int j = 0; j < MAX; j++) for (int k = 0; k < MAX; k++) ret[i][j][k] = 0;

    ios::sync_with_stdio(false);
    
    while (true) {
        cin >> A >> B >> C;
        if (A == -1 && B == -1 && C == -1) break;

        cout << "w(" << A << ", " << B << ", " << C << ") = "<< w(A, B, C) << endl;
    }
    return 0;
}
