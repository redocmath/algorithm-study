#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n, k, root;

struct Node {
    int n;
    vector<Node> children;
};

vector<int> a;

int countleaf = 0;

Node construct(int node) {
    Node tree;
    tree.n = node;
    bool isleaf = 1;
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        if (a[i] == node) {isleaf = 0; tree.children.push_back(construct(i));}
    }
    if (isleaf) countleaf++;
    return tree;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {int t; cin >> t; a.push_back(t); if (t == -1) root = i;}
    cin >> k;
    if (root == k) {cout << 0; return 0;}
    construct(root);
    cout << countleaf;
    return 0;
}
