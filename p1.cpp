#ifndef CP_TEMPLATE_ORZING
#define CP_TEMPLATE_ORZING

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdint>

using namespace std;

using ll = long long;
using u32 = uint32_t;
using u64 = uint64_t;
using ld = long double;

#define endl '\n'
#define sz(x) int((x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define pb push_back
#define ff first
#define ss second

template<class T>
bool chmin(T& a,T b){
    if (b < a){
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T& a,T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

#ifdef DEBUG
#define dbg(...)                                           \
    cerr << "L" << __LINE__ << " [" << #__VA_ARGS__ << "]" \
         << ": ";                                          \
    [](auto&& __a, auto&&... __b) -> void {                \
        cerr << __a;                                       \
        ((cerr << " | " << __b), ...);                    \
        cerr << endl;                                      \
    }(__VA_ARGS__);
#else
#define cerr   \
    if (false) \
    cerr
#define dbg(...)
#endif

#endif


void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int m = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        a[i].resize(k);
        m = max(m,k);
        for(int j = 0;j < k; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> col(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < sz(a[i]); j++){
            col[j].pb(i);
        }
    }

    vector<int> rank(n);
    vector<int> best(m);
    for(int p = m-1; p >= 0; p--){
        vector<pair<pair<int,int>,int>> v;
        for(int i : col[p]){
            int nxt;
            if(p+1 == sz(a[i])){
                nxt = 0;
            }
            else{
                nxt= rank[i];
            }
            v.pb({{a[i][p],nxt}, i});
        }
        sort(all(v));
        int r = -1;
        pair<int,int> last = {-1,-1};
        for(auto x : v){
            if(x.ff != last){
                r++;
                last = x.ff;
            }
            rank[x.ss] = r;
        }
        best[p] = v[0].ss;
    }
    vector<int> ans;

    int p =0;
    while(p < m){
        int i = best[p];
        for(int j = p; j < sz(a[i]); j++){
            ans.pb(a[i][j]);
        }
        p=sz(a[i]);
    }
    for(int i = 0; i < sz(ans); i++){
        if(i){
            cout <<' ';
        }
        cout <<ans[i];
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}