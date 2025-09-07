#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> mp;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    
    bool ok = true;
    ll cnt = 0;
    for (auto [value, times] : mp) {
        ok &= times % value == 0;
        cnt += times;
    }
    
    ok &= cnt == n;
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    ll current = 1;
    map<ll, vector<ll>> idx;
    for (auto [value, times] : mp) {
        ll increase = times / value;
        for (ll i = 0; i < increase; i++) {
            idx[value].push_back(current);
            current++;
        }
        idx[value].push_back(-1);
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; i++) {
        ll times = mp[a[i]];
        if (times % a[i] == 0) idx[a[i]].pop_back();
        ll x = idx[a[i]].back();
        ans[i] = x;
        mp[a[i]]--;
    }
    print_vec(ans);
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