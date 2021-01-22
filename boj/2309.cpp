#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int heights[9];
    for (int i = 0; i < 9; i++) {
        cin >> heights[i];
    }

    sort(heights, heights+9);

    int sum = 0;
    for (int i = 0; i < 9; i++) {
        sum += heights[i];
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j) continue;
            if (sum - heights[i] - heights[j] == 100) {
                for (int k = 0; k < 9; k++) {
                    if (k == i || k == j) continue;
                    cout << heights[k] << endl;
                }
                return 0;
            }
        }
    }
}
