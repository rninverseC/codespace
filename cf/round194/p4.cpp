#include <iostream>
using namespace std;
using ll = long long;

void solve(){
    int n; cin>>n;
    string s;
    cin>> s;
    if(s[0] == '0' || s.find("00")!=string::npos){
        cout << -1 << endl;
        return;
    }
    bool ok = true;
    for(int i = 0; i<n; i++){
        if(s[i] == '0' && i%2 ==0){
            ok = false;
        }
        if(i > 0 && s[i] != '0' && s[i-1] != '0' && s[i] != s[i-1]){
            ok = false;
        }

    }
    
    if(ok){
        cout << 1<<endl;
        return;
    }
    if(s.find("+--+") != string::npos || s.find("-++-") != string::npos){
        cout << 3 << endl;
        return;
    }
    cout <<2<< endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--) solve();
}