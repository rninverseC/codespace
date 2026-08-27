#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<ll> pre(n+1);
    for(int i = 1; i<=n; i++){
        ll x; cin>>x;
        pre[i]=pre[i-1]+x;
    }
    ll ans=0;
    for(int i = 1; i<=n; i++){
        if(n%i !=0) continue;
        ll mn = LLONG_MAX;
        ll mx = LLONG_MIN;
        for(int j=0; j<n; j+=i){
            ll sum = pre[j+i] - pre[j];
            mn = min(mn, sum);
            mx = max(mx, sum);
        }
        ans = max(ans, mx-mn);
    }
    cout << ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}