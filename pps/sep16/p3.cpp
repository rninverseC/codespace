#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<array<ll, 3>> points(m);
    for(int i = 0; i<m; i++){
        ll x,w;
        cin>>x>>w;
        points[i][0] = w;
        points[i][1] = x;
        points[i][2] = i+1;
        }
        sort(points.begin(), points.end());
        ll total = 0;
        vector<pair<ll,int>> selected;
        for(int i = 0; i<2*n; i++){
            total+=points[i][0];
            ll cord = points[i][1];
            int ind = points[i][2];
            selected.push_back({
                cord,ind
            });
        }
        sort(selected.begin(),selected.end());
        cout<<total<<endl;
        for(int i = 0; i<n; i++){
            int lft = selected[i].second;
            int rt = selected[2*n-1-i].second;
            cout<<lft<<" "<<rt<<endl;
        }
        cout<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}