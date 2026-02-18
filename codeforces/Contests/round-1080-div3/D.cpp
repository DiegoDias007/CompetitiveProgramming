#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> f(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector<ll> ans(n + 1);
    for (ll i = 2; i < n; i++) {
        ans[i] = -2*f[i] + f[i - 1] + f[i + 1];
        ans[i] /= 2;
    }

    ans[1] = f[n];
    ans[n] = f[1];

    // ans[1]
    for (ll i = 2; i <= n; i++) {
        ll j = n - i;
        ans[1] -= ans[i] * j; 
    }

    ans[1] /= (n - 1);

    // ans[n]
    for (ll i = 1; i < n; i++) {
        ll j = i - 1;
        ans[n] -= ans[i] * j;
    }

    ans[n] /= (n - 1);

    for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << endl;
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