#include <iostream>
#define MAX 15

using namespace std;

int N, T[MAX], P[MAX];


int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }
    return 0;
}
