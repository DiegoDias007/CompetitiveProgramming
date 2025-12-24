#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<ll> pl(n + 2), sl(n + 2);
    
    for (ll i = 1; i <= n; i++) pl[i] = pl[i - 1] + (l - a[i - 1]);
    for (ll i = n; i >= 1; i--) sl[i] = sl[i + 1] + (a[i - 1] - l);
    
    vector<ll> pr(n + 2), sr(n + 2);

    for (ll i = 1; i <= n; i++) pr[i] = pr[i - 1] + (r - a[i - 1]);
    for (ll i = n; i >= 1; i--) sr[i] = sr[i + 1] + (a[i - 1] - r);

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll score_l = pl[i] + sl[i + 1];
        ll score_r = pr[i] + sr[i + 1];

        ans = max(ans, min(score_l, score_r));

        if (i == 0) continue;
        
        score_l = pl[i - 1] + sl[i + 1];
        score_r = pr[i - 1] + sr[i + 1];
        ans = max(ans, min(score_l, score_r));
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