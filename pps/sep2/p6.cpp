#include <iostream>
#include <vector>
#include <algorithm>
#include<climits>
#include <array>
using namespace std;
using ll = long long;


void solve(){
    int n,m;
    cin >> n>>m;
    int r; cin>>r;
    vector<array<ll,3>> shots(r);
    for(int i = 0; i<r; i++){
        cin>>shots[i][0] >> shots[i][1] >> shots[i][2];
    }
    sort(shots.begin(),shots.end());
    vector<vector<int>> can(n+1, vector<int>(m+1));
    can[0][0] = 1;
    ll cur=0;
    int p=0;
    while(p<r){
        ll t=shots[p][0];
        int best = -1;
        for(int i = 0; i <=n; i++){
            for(int j = 0; j<=m; j++){
                if(can[i][j]){
                    best = max(best,i+j);
                }
            }
        }
        if (best != -1){
            ll finish = cur+(n+m-best);
            if (finish <t){
                cout << finish<<endl;
                return;
            }
        }
        ll dt = t-cur;
        vector<vector<int>> pref(n+1, vector<int>(m+1,-1));
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(can[i][j]){
                    pref[i][j] = i+j;
                }
                if(j>0){
                    pref[i][j] = max(pref[i][j], pref[i][j-1]);
                }
            }
        }

        vector<vector<int>> next(n+1, vector<int>(m+1));
        for(int i = 0; i<= n; i++){
            for(int j = 0; j<=m; j++){
                if(pref[i][j] >= i+j-dt){
                    next[i][j]=1;
                }
            }
        }
        vector<int> row(n+1);
        vector<int> col(m+1);
        while(p<r && shots[p][0]==t){
            int d= shots[p][1];
            int coord = shots[p][2];
            if(d==1){
                row[coord] = 1;
            }
            else{
                col[coord] = 1;
            }
            p++;
        }
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(row[i] || col[j]){
                    next[i][j] = 0;
                }
            }
        }
        can = next;
        cur = t;
    }
    int best = -1;
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            if(can[i][j]){
                best = max(best,i+j);
            }
        }
    }
    if(best == -1){
        cout<<-1<<endl;
    }
    else cout<<cur+n+m-best<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}