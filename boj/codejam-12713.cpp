// 여러분 stoi는 없애야 합니다.
// 여러분 stoi는 꼭 필요합니다.
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int digitPrime[] = {2, 3, 5, 7};
string num; 
long long ans = 0;

bool isUgly(long n) {
    if (n == 0) return true;
    
    for (int i = 0; i < 4; i++) {
        if (n % digitPrime[i] == 0) return true;
    }

    return false;
}

void solve(int cur, long long sum) {
    if (cur == num.length()) {
        if (isUgly(sum)) ans++;
        return;
    }
    long long nxt = 0;
    for (int i = cur; i < num.length(); i++) {
        nxt *= 10;
        nxt += num[i] - '0';
        
        solve(i + 1, sum + nxt);
        if (cur != 0) {
            solve(i + 1, sum - nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num;
        ans = 0;
        solve(0, 0);
        cout << "Case #" << i+1 << ": " << ans << "\n";
    }
    return 0;
}
