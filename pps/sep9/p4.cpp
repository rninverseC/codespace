#include <iostream>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    vector<int> prefix(n+1, 0);
    for(int i = 0; i<n; i++){
        cin>>a[i];
        prefix[i+1]=prefix[i]+(abs(a[i])==2);
    }

}


int main(){
    ios:sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}