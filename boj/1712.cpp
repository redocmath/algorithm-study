#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c - b > 0) cout << (a / (c - b) + 1);
    else cout << "-1";
}
