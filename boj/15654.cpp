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
int arr[8];

void func(int k, int last) { 
  if (k == m){ 
       for (int i = 0; i < m; i++)
           cout << arr[i] << ' ';
       cout << '\n';
       return;
  }

  for (int i = last; i <= n; i++){
    arr[k] = i; 
    func(k+1, i); 
  }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    func(0, 1);
}
