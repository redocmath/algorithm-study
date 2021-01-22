#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, count = -1;
    cin >> n;

    int minCount = 999999999;
    for (int i = 0; i <= n / 5; i++) {
        count = i;
        int newn = n - (i * 5);

        if (newn % 3 != 0) continue;
        else {
            if (minCount > (count + newn / 3)) minCount = count + newn / 3;
        }
    }

    if(minCount != 999999999) cout << minCount;
    else cout << string("-1");
}
