#ifndef CP_TEMPLATE
#define CP_TEMPLATE

#include <iostream>
#include <vector>
#include <string>
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

    vector<int> p(n + 1);
    vector<int> dep(n + 1);

    for(int i = 2; i <= n; i++){
        cin >> p[i];
        dep[i] = dep[p[i]] + 1;
    }

    int m;
    cin >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++){
        cin >>a[i];
    }

    int keep = a[0];
    for(int v : a){
        if(dep[v] < dep[keep]){
            keep = v;
        }
    }

    cout << m - 1;
    for(int v : a){
        if(v != keep){
            cout << ' ' << v;
        }
    }
    cout<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();

}
