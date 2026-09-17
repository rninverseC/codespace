#include <iostream>
using namespace std;

void solve(){
    string s; cin>>s;
    char c; cin>>c;
    for(int i = 0; i<s.size(); i++){
        if(s[i]== c && i%2==0){
            cout<< "YES" << endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--) solve();
}