#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> g;
vector<vector<int>>  seg;
vector<int> tin, tout, a;
int timer;

void dfs(int v, int par){
    tin[v] = timer++;
    for(int x: g[v]){
        if(x==par) continue;
        dfs(x, v);
    }
    tout[v] = timer-1;
}

void build(int node, int l, int r){
    if(l==r){
        seg[node].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(node*2, l, mid);
    build(node*2+1, mid+1, r);
    merge(
        seg[node*2].begin(), seg[node*2].end(),
        seg[node*2+1].begin(), seg[node*2+1].end(),
        back_inserter(seg[node])
    );
}

bool query(int node, int l, int r, int ql, int qr, int low, int high){
    if(qr<l || r<ql) return false;
    if(ql<=l && r<=qr){
        auto it = lower_bound(seg[node].begin(), seg[node].end(),low);
        return it != seg[node].end() && *it <= high;
    }

    int mid = (l+r)/2;
    return query(node*2, l, mid, ql, qr, low, high) || query(node*2+1, mid+1, r, ql, qr, low, high);
}

void solve(){
    int n,q; cin>>n>>q;
    g.assign(n+1, {});
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);
    a.assign(n+1, 0);
    seg.assign(4*n+5,{});
    for(int i=0; i<n-1;i++){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    timer = 0;
    dfs(1,0);
    for(int i = 1; i<=n; i++){
        int x; cin>>x; 
        a[i]=tin[x];
    }
    build(1,1,n);
    while(q--){
        int l,r,x;
        cin>>l>>r>>x;
        cout<< (query(1,1,n,l,r,tin[x],tout[x]) ? "YES":"NO") << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}////goooooon problem