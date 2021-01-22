#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b || a < b) {
        a > b ? cout << ">" : cout << "<";
        return 0;
    }
    cout << "==";
    return 0;
}