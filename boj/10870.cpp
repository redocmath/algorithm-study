/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <iostream>
using namespace std;

int pib(int n) {
    if (n == 0) return 0;
    else if (n == 1) return 1;
    return pib(n - 2) + pib(n - 1);
}
int main() { 
    int n;
    cin.sync_with_stdio(false);
    cin >> n;
    cout << pib(n);
    return 0;
}
