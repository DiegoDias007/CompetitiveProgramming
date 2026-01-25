#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    ll mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        ll cur_mn = min(min(mx - a[i], mn - a[i]), min(b[i] - mx, b[i] - mn));
        ll cur_mx = max(max(mx - a[i], mn - a[i]), max(b[i] - mx, b[i] - mn));
        mn = cur_mn;
        mx = cur_mx;
    }
    cout << mx << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}