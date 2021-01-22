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
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int a = x < y ? x : y;
    int b = w - x < h - y ? w - x: h - y;

    cout << (a < b ? a : b);
    return 0;
}

