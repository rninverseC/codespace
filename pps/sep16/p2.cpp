#include <iostream>
using namespace std;
using ll = long long;

template<class T>
bool chmax(T& a,T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}
ll calc(ll x, ll a){
    return x/a+x%a;
}

void solve(){
    ll r,a,l;
    cin>>l>>r>>a;
    ll ans = calc(r,a);
    ll x = r-(r+1)%a;
    if(x>=l){
        chmax(ans,calc(x,a));
    }
    cout << ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}