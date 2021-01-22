/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int x, y;
    vector<int> X(3);
    vector<int> Y(3);

    for (int i = 0; i < 3; i++) {
        int tempx, tempy;
        cin >> tempx >> tempy;
        
        X[i] = tempx;
        Y[i] = tempy;
    }

    if (X[0] == X[1]) x = X[2];
    else if (X[0] == X[2]) x = X[1];
    else x = X[0];

    if (Y[0] == Y[1]) y = Y[2];
    else if (Y[0] == Y[2]) y = Y[1];
    else y = Y[0];

    cout << x << " " << y;
    return 0;
}
