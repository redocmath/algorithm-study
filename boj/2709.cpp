#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
typedef long long ll;
using namespace std;

ll k[20] = {1, 9, 89, 89, 589, 3089, 3089, 3089, 315589, 315589, 8128089, 164378089, 945628089, -1, 11687815589, -1, -1, -1, -1, -1};

ll tmp = 1; ll ans = 1;

void getR(int r) {
    while(true) {
        ans = (ans * 2) % ((ll)pow(10, r));
        string tmp2 = to_string(ans);
        
        bool isValid = true;
        for (int i = 0; i < r; i++) {
            if ((tmp2[i] != '1') && (tmp2[i] != '2')) isValid = false;
        }

        if (isValid) break;
        tmp++;
    }
    cout << tmp;
}

int main() {
    ios::sync_with_stdio(false);
    getR(13);
    //:TODO your code
    return 0;
}
