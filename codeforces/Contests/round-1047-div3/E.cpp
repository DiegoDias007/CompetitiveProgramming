#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll calc_mex(vector<ll> a, ll n) {
    vector<ll> seen(n + 1, 0);
    for (auto x : a) {
        if (x <= n) seen[x] = true;
    }

    for (ll i = 0; i <= n; i++) {
        if (!seen[i]) return i;
    }
    return n;
}

vector<ll> do_it(vector<ll> a, ll n) {
    map<ll, ll> cnt;
    for (ll i = 0; i < n; i++) cnt[a[i]]++;

    ll mex = calc_mex(a, n);

    vector<ll> new_a(n);
    for (ll i = 0; i < n; i++) {
        if (a[i] > mex) {
            new_a[i] = mex;
        } else {
            if (cnt[a[i]] == 1) new_a[i] = a[i];
            else new_a[i] = mex;
        }
    }
    return new_a;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }   

    a = do_it(a, n);
    k--;
    if (k == 0) {
        ll sum = 0;
        for (auto x : a) sum += x;
        cout << sum << endl;
        return;
    }

    a = do_it(a, n);
    if (k % 2 == 0) {
        a = do_it(a, n);
    }

    ll ans = 0;
    for (auto x : a) ans += x;
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