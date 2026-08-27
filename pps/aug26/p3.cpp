#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdint>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll cur=a[0];
    ll ans=a[0];
    for(int i=1; i<n; i++){
        if(abs(a[i]%2) != abs(a[i-1]%2)){
            cur = max(a[i], cur+a[i]);
        }
        else{
            cur=a[i];
        }
        ans = max(ans,cur);
    }
    cout << ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}