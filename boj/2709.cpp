#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll k[20] = {1, 9, 89, 89, 589, 3089, 3089, 3089, 315589, 315589, 8128089, 164378089, 945628089, 1922190589, 11687815589, -1, -1, -1, -1, -1};

ll tmp = 1; ll ans = 1;

void getR(int r) {
    bool isValid = true;
    while(true) {
        ans = (ans * (tmp == 1 ? 2 : 16)) % ((ll)pow(10, r));
        string tmp2 = to_string(ans);
        
        isValid = true;
        for (int i = 0; i < r; i++) {
            if ((tmp2[i] != '1') && (tmp2[i] != '2')) isValid = false;
        }

        if (isValid) break;
        tmp += 4;
    }
    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    getR(16);
    tmp = 1; ans = 1;
    getR(17);
    tmp = 1; ans = 1;
    getR(18);
    tmp = 1; ans = 1;
    getR(19);
    tmp = 1; ans = 1;
    getR(20);
    return 0;
}
