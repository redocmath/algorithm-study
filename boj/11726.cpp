#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000

using namespace std;

int N;
int cache[MAX + 1];

int main() {
    cache[1] = 1;
    cache[2] = 2;

    ios::sync_with_stdio(false);
    cin >> N;

    // bottom-up
    for (int i = 3; i <= N; i++) {
        cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
    } 

    cout << cache[N] << endl;
    return 0;
}
