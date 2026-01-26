#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n;
    cin >> n;
    set<ll> a;
    for (ll i = 0; i < n; i++) {
        ll ai;
        cin >> ai;
        a.insert(ai);
    }

    vector<ll> ans(n + 1, -1);
    for (auto x : a) {
        ans[x] = 1;
        for (ll i = 1; i * x <= n; i++) {
            if (ans[i] == -1) continue;
            
            ll j = i * x;
            if (ans[j] == -1) ans[j] = ans[i] + 1;
            else ans[j] = min(ans[j], ans[i] + 1);
        }
    }

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