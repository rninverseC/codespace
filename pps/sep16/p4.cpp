#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void solve(){
    int n; cin>>n;
    vector<int> perm(n);
    vector<int> ans(n,0);
    for(int i = 0; i<n; i++){
        cin>>perm[i];
    }
    for(int i = n; i>=1; i--){
        int pos=-1;
        for(int j = 0; j<i; j++){
            if(perm[j] == i){
                pos=j;
                break;
            }
        }
        int shift;
        if(pos == i-1){
            shift = 0;
        }
        else{
            shift=pos+1;
        }
        ans[i-1]=shift;
        rotate(
            perm.begin(),
            perm.begin()+shift,
            perm.begin()+i
        );
    }
    for(int i = 0; i<n;i++){
        cout<<ans[i];
        if(i+1<n){
            cout << " ";
        }
    }
    cout<<endl;

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}