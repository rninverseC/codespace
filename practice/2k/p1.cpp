#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
using ll = long long;
using ld = long double;

struct Point{
    ll x,y;
    bool operator<(const Point& other) const{
        if(x!= other.x) return x<other.x;
        return y<other.y;
    }
};

ll cross(Point a, Point b, Point c){
    return (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
}

void solve(){
    int n;
    ll r;
    cin >> n >> r;
    vector<Point> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a.begin(),a.end());
    vector<Point> h;
    for(Point x:a){
        while(int(h.size()) >= 2 && cross(h[int(h.size()-2)], h.back(), x) <= 0){
            h.pop_back();
        }
        h.push_back(x);
    }
    h.pop_back();
    const ld  pi = acosl(-1.0L);
    if(int(h.size())<3){
        cout << fixed<< setprecision(15) << pi*r*r/2<<endl;
        return;
    }
    bool inside = true;
    for(int i = 0; i<int(h.size()); i++){
        Point a= h[i];
        Point b = h[(i+1)%int(h.size())];
        //cross ab origin
        ll c= a.x*b.y-a.y*b.x;
        if(c<=0){
            inside = false;
            break;
        }
    }
    if (!inside){
        cout<<fixed << setprecision(15) << pi*r*r/2<<endl;
        return;
    }
    ld d= 1e30L;
    for(int i = 0; i<int(h.size());i++){
        Point a= h[i];
        Point b = h[(i+1)% int(h.size())];
        ld num = fabsl((ld)a.x*b.y-(ld)a.y*b.x);
        ld dx = b.x-a.x;
        ld dy = b.y-a.y;
        ld cur = num/sqrtl(dx*dx+dy*dx);
        d=min(d,cur);
    }
    ld R =r ;
    ld ans = R*R*acosl(d/R) - d*sqrtl(R*R-d*d);
    cout <<  fixed<<setprecision(15)<<ans<<endl;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}