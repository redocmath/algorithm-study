#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    
    if (m < 45) {
        cout << (h == 0 ? 23 : h - 1) << " " << 60 - (45 - m);
        return 0;
    }
    cout << h << " " << m - 45;
    return 0;
}