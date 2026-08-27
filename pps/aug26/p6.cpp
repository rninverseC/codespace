#include <iostream>
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=1; i<n-1; i++){
        cout<<i<< " " << i+1<<endl;
    }
    cout << n << " " << 2 << endl;
    int cur = 2;
    while(q--){
        int d; cin>>d;
        if(d==cur){
            cout<<-1<<" "<<-1<<" " << -1<<endl;
        }
        else{
            cout<<n<<" "<<cur<<" "<<d<<endl;
            cur = d;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}