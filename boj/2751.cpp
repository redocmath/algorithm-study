#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, temp; vector<int> sorted;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sorted.push_back(temp);
    }

    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < n; i++) cout << sorted[i] << '\n';

    return 0;
}
