/*
 * Merry Christmas!
 * 메리 크리스마스!
 *
 * */

#include <iostream>
#include <vector>
using namespace std;

int main() { 
    int n, m;
    cin.sync_with_stdio(false);
    cin >> n >> m;
    vector<int> cards(n);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        cards[i] = temp;
    }

    int similarSum = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k || cards[i] + cards[j] + cards[k] > m) continue;
                if (m - (cards[i] + cards[j] + cards[k]) < m - similarSum) similarSum = cards[i] + cards[j] + cards[k];
            }
        }
    }

    cout << similarSum;
    return 0;
}
