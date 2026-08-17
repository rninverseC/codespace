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
    ll s;
    int q;
    cin >> s >> q;
    vector<ll> d;
    for(ll i = 1; i <= s/i; i++){
        if (s%i==0){
            d.pb(i);
            if(i != s/i){
                d.pb(s/i);
            }
        }
    }
    sort(all(d));
    int n = sz(d);
    vector<ll> pref(n);
    ll last = 0;
    for(int i = 0; i < n; i++){
        ll wid = d[i] - last;
        ll height = s/d[i];
        pref[i] = wid * height;
        if(i > 0){
            pref[i] += pref[i - 1];
        }
        last = d[i];
    }
    while(q--){
        ll x,y;
        cin >> x >> y;
        ll limit = s/y;
        int j = upper_bound(all(d), limit) - d.begin() - 1;
        ll w = d[j];
        if(x <= w){
            cout << x*y << endl;
            continue;
        }
        int k = lower_bound(all(d), x) - d.begin();
        ll prev = 0;
        ll fx = 0;
        if (k > 0){
            prev = d[k-1];
            fx = pref[k-1];
        }
        fx += (x-prev) * (s/d[k]);
        ll ans = w*y+fx-pref[j];
        cout << ans <<endl;
    
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}