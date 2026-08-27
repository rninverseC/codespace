#include <iostream>
using namespace std;

void solve() {
    int n; cin>>n;
        if (n%3 != 0) {
        cout << "First"<<endl;
    } else {
        cout << "Second"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
}
