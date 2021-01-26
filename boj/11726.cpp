#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i, start, end) for (int i = (start); i < (end); i++)
#define MAX 1000

using namespace std;

int N;
int cache[MAX];

int getCases(int width) {
    int& tmp = cache[width];

    if (tmp != -1) return tmp;
    return tmp = (getCases(width - 1) + getCases(width - 2)) % 10007;
}

int main() {
    FOR(i, 0, MAX) {
        cache[i] = -1;
    }
    cache[1] = 1;
    cache[2] = 2;

    ios::sync_with_stdio(false);
    cin >> N;
    cout << getCases(N);
    return 0;
}
