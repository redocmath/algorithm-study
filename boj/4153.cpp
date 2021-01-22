/*
 * Merry Christmas, two!
 * 메리 크리스마스22!
 *
 * */

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;
        vector<int> abc(3);

        abc[0] = a;
        abc[1] = b;
        abc[2] = c;

        sort(abc.begin(), abc.end());

        if (abc[2] * abc[2] == abc[0] * abc[0] + abc[1] * abc[1]) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}
