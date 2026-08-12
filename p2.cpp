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






const int N = 435;

void solve(){
    int n, k;
    cin >> n >> k;

    int total = n * (n - 1) / 2;
    int need = total - k;

    vector<vector<int>> pre(n + 1, vector<int>(need + 1, -1));
    pre[0][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= need; j++){
            if(pre[i][j] == -1) continue;

            for(int len = 1; i + len <= n; len++){
                int add = len * (len - 1) / 2;
                if(j + add > need) break;

                if(pre[i + len][j + add] == -1){
                    pre[i + len][j + add] = len;
                }
            }
        }
    }

    if(pre[n][need] == -1){
        cout << 0 << endl;
        return;
    }

    vector<int> lens;

    int i = n;
    int cur = need;

    while(i > 0){
        int len = pre[i][cur];
        lens.pb(len);

        i -= len;
        cur -= len * (len - 1) / 2;
    }

    reverse(all(lens));

    vector<int> ans;
    int mx = n;

    for(int len : lens){
        for(int x = mx - len + 1; x <= mx; x++){
            ans.pb(x);
        }
        mx -= len;
    }

    for(int i = 0; i < n; i++){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();
}