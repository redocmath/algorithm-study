#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;


int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int h, w, n;
        cin >> h >> w >> n;

        cout << ((n % h) == 0 ? h : (n % h)) << setfill('0') << setw(2) << (int)ceil((double)n / (double)h) << endl;
    }
    return 0;
}
