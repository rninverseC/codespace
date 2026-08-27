#include "bits/extc++.h"

using namespace std;

using ll = long long;

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int minele=1e9;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        minele=min(minele,arr[i]);
    }
    int pos=0;
    for(int i = 0; i<n; i++){
        if(arr[i]==minele){ pos=i; break; }
    }
    bool fail=0;
    for(int i = pos; i<n-1; i++){
        if(arr[i+1]<arr[i]) fail=1;
    }
    if(fail){
        cout<<"-1\n";
        return;
    }
    cout<<pos<<"\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(ios::failbit);
    int t;
    cin>>t;
    while(t--) solve();
}