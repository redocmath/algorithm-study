#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <functional>
#include <utility>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;

int n, m; 
int arr[7];

void func(int k) { 
  if (k == m){ 
       for (int i = 0; i < m; i++)
           cout << arr[i] << ' ';
       cout << '\n';
       return;
  }

  for (int i = 1; i <= n; i++){
    arr[k] = i; 
    func(k+1); 
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    func(0);
}