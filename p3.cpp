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
#include <string>

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
    priority_queue<pair<int,int>> pq;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x >= n){
            cout << "IMPOSSIBLE" << endl;
            return;
        }

        sum += x;
        if(x > 0){
            pq.push({x, i});
        }
    }
    if(sum % 2){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<pair<int,int>> ans;
    while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > sz(pq)){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        vector<pair<int,int>> cur;

        for(int i = 0; i < d; i++){
            auto [x, v] = pq.top();
            pq.pop();
            ans.pb({u, v});
            x--;
            if(x > 0){
                cur.pb({x, v});
            }
        }

        for(auto x : cur){
            pq.push(x);
        }
    }

    cout << sz(ans) << endl;
    for(auto [u, v] : ans){
        cout << u << ' ' << v << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    solve();
}