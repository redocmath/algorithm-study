#include <bits/stdc++.h>
 
using namespace std;
 
bool cmp(pair<int, int> f, pair<int, int> s) {
    if (f.second == s.second)
        return f.first < s.first;
    else
        return f.second < s.second; 
}
 
int main() {
    int N;
    cin >> N;
 
    vector<pair<int, int>> t(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i].first >> t[i].second;
    }
 
    sort(t.begin(), t.end(), cmp);
 
    int cnt = 0; 
    int n = 0; 
 
    for (int i = 0; i < t.size(); i++) {
        if (n <= t[i].first) { 
            n = t[i].second;
            cnt++; 
       }
    }
 
    cout << cnt << endl;
} 
