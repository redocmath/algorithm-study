#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long cache[101];

long getSequence(int n) {
    long& tmp = cache[n];
    if (tmp != -1) return tmp;
    return tmp = getSequence(n - 2) + getSequence(n - 3); 
}
int main() {
    for (int i = 0; i < 101; i++) {
        cache[i] = -1;
    }
    cache[1] = 1; cache[2] = 1; cache[3] = 1;

    ios::sync_with_stdio(false);
    int T, N;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << getSequence(N) << endl;
    }

    return 0;
}
