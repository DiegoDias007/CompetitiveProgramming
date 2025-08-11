// https://atcoder.jp/contests/abc415/tasks/abc415_d

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m);;
    for (int i = 0; i < m; i++) {
        ll ai, bi;
        cin >> ai >> bi;
        a[i] = {ai - bi, ai};
    }

    ll ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        ll lose = a[i].first, ai = a[i].second;
        if (n < ai) continue; 
        ll dif = n - ai;
        ll n_times_can_take = dif / lose + 1;
        ans += n_times_can_take;
        n -= n_times_can_take * lose;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}