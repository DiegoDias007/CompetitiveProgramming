#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        b.push_back(a[i] - m);
        b.push_back(a[i]);
        b.push_back(a[i] + m);
    }

    sort(b.begin(), b.end());

    int N = 3*n;
    vector<ll> ps(N + 1);
    for (int i = 1; i <= N; i++) ps[i] = ps[i - 1] + b[i - 1];
    
    ll ans = 1e18;
    for (int i = n; i < 2*n; i++) {
        int x = b[i];
        int left = x - m / 2;
        int right = x + (m - 1) / 2;

        int l = lower_bound(b.begin(), b.end(), left) - b.begin();
        int r = upper_bound(b.begin(), b.end(), right) - b.begin() - 1;

        ll cost_left = 1ll * (i - l + 1) * x - (ps[i + 1] - ps[l]);
        ll cost_right = -1ll * (r - i + 1) * x + (ps[r + 1] - ps[i]);
        ans = min(ans, cost_left + cost_right); 
    }
    cout << ans << endl;
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