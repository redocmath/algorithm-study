/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <iostream>
using namespace std;

int fac(int n) {
    if (n == 1) return 1;
    return n * fac(n - 1);
}
int main() { 
    int n;
    cin.sync_with_stdio(false);
    cin >> n;
    if (n == 0) cout << "1";
    else cout << fac(n);
    return 0;
}
