#include <bits/stdc++.h>
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast") 
#pragma gcc optimize("unroll-loops")
typedef long long ll;
using namespace std;
typedef pair<int, int> P;
typedef vector<int> V;

int n;
int tree[26][2];

void preorder(int node) {
    cout << char(node+'A'); 
    if (tree[node][0] != -1) preorder(tree[node][0]);
    if (tree[node][1] != -1) preorder(tree[node][1]);
}

void inorder(int node) {
    if (tree[node][0] != -1) inorder(tree[node][0]);
    cout << char(node+'A'); 
    if (tree[node][1] != -1) inorder(tree[node][1]);
}

void postorder(int node) {
    if (tree[node][0] != -1) postorder(tree[node][0]);
    if (tree[node][1] != -1) postorder(tree[node][1]);
    cout << char(node+'A'); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char root, l, r; cin >> root >> l >> r;
        tree[root-'A'][0] = (l == '.' ? -1 : l-'A');
        tree[root-'A'][1] = (r == '.' ? -1 : r-'A');
    }
    preorder(0);
    cout << "\n";
    inorder(0);
    cout << "\n";
    postorder(0);
    cout << "\n";
    return 0;
}
