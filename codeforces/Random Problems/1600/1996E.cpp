// https://codeforces.com/problemset/problem/1996/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    ll n = s.size();
    map<ll, vector<ll>> idxs;
    set<ll> sms;
    ll sm = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == '0') sm++;
        else sm--;
        idxs[sm].push_back(i);
        sms.insert(sm);
    }

    map<ll, vector<ll>> ps;
    for (auto sm : sms) {
        ll size = idxs[sm].size();
        ps[sm] = vector<ll>(size + 1);
        for (ll j = 1; j <= size; j++) {
            ll y = idxs[sm][j - 1];
            ps[sm][j] = (ps[sm][j - 1] + (n - y)) % MOD;
        }
    }

    ll ans = 0;
    sm = 0;
    for (ll i = -1; i < n; i++) {
        if (i != -1) {
            if (s[i] == '0') sm++;
            else sm--;
        }
        ll size = idxs[sm].size();
        auto ptr_y = lower_bound(idxs[sm].begin(), idxs[sm].end(), i + 2);
        if (ptr_y == idxs[sm].end()) continue;
        ll idx_y = ptr_y - idxs[sm].begin();
        ll sum_y = ps[sm][size] - ps[sm][idx_y];
        ll intervals = ((i + 2) * sum_y) % MOD;
        ans = (ans + intervals) % MOD;
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