#include <iostream>
using namespace std;
using ll = long long;
void solve(){
    int n; cin>>n;
    ll mx1 = 0;
    ll mx2 = 0;
    for(int i = 0; i<n; i++){
       ll x;cin>>x;
       if(x>mx1){
        mx2=mx1;
        mx1=x;
       }
       else if(x>mx2){
            mx2=x; 
        }
    }
    if(mx1-mx2<=1){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}