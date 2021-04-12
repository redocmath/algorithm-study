#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const string a[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
const int b[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prfx[12] = {0, };

int main() {
    ios::sync_with_stdio(false);
    for (int i = 1; i < 12; i++) {
        prfx[i] = b[i-1] + prfx[i-1];
    }
    int x, y; cin >> x >> y;
    
    cout << a[(prfx[x-1] + y-1) % 7];
    return 0;
}
