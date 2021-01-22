/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <iostream>
#include <vector>
using namespace std;

int main() { 
    int n, constructor = 0;
    cin.sync_with_stdio(false);
    cin >> n;

    for (int i = 1; i < n; i++) {
        if (i + i / 100000 + (i / 10000) % 10 + (i / 1000) % 10 + (i / 100) % 10 + (i / 10) % 10 + i % 10 == n && constructor == 0) {
            constructor = i;
            break;
        }
    }

    cout << constructor;
    return 0;
}
