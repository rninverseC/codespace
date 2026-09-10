#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin>>s;
    int valid = 0;
    vector<bool> seen(26, false);
    for(char c : s){
        int idx = c - 'a';
        if (seen[idx]) {
            valid++;
            fill(seen.begin(), seen.end(), false);
        } else {
            seen[idx]=true;
        }
    }
    cout << s.length() - (valid * 2) <<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
