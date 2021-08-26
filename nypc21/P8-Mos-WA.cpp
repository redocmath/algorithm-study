#include <bits/stdc++.h>
#define PII pair<int,int>
#define PIII pair<PII,int>
 
using namespace std; 

const int N = 1000005, M = 500005, SQRT_N = 1000;
PII query[N];
PIII order[N];
PII c[N];
int cnt[M];
int a[N];
int n,q;
int an;
int ans[M];
int ret = 0;
 
void add(int idx){
    if(cnt[a[idx]]==0) an++; 
    cnt[a[idx]]++;
}
 
void erase(int idx){
    cnt[a[idx]]--;
    if(cnt[a[idx]]==0) an--; 
}
 
void Query(PII prev, PII now){
    int l1 = prev.first;
    int r1 = prev.second;
    int l2 = now.first;
    int r2 = now.second;
    for(int i = l1-1; i>=l2; i--) add(i); // l1 > l2 add node 
    for(int i = r1+1; i<=r2; i++) add(i); // r1 < r2 add node 
    for(int i = l1; i<l2; i++) erase(i); // l1 < l2 erase '' 
    for(int i = r1; i>r2; i--) erase(i); // same 
}
 
int main(){
    scanf("%d",&n);
    n *= 2;
    for(int i=1; i<=n; i++){
        scanf("%d",&a[i]);
        c[i] = {a[i], i};
    }

    sort(c+1, c+n+1);

    q = n/2;

    for (int i=1; i<=q; i++){
        query[i].first = c[1 + 2*(i-1)].second, query[i].second = c[1 + 2*(i-1)+1].second;
        order[i].first = PII(query[i].first/SQRT_N, query[i].second);
        order[i].second = i;
    }
    sort(order+1, order+q+1);
    for (int i=1; i<=q; i++){
        Query(query[order[i-1].second], query[order[i].second]);
        ans[order[i].second] = an-1;
    }

    for (int i = 1; i <= q; i++) {
        ret += 2 * ans[i] - (c[1 + 2*(i-1) + 1].second - c[1 + 2*(i-1)].second - 1);
    }

    cout << ret / 2 + q + 1;
    return 0;
}
