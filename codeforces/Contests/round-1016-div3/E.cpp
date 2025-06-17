#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool ok(vector<ll>& a, ll k, ll mex) {
    ll n = a.size();
    ll segments = 0;
    vector<int> current(mex);
    int have = 0;
    for (ll i = 0; i < n; i++) {
        if (a[i] < mex && current[a[i]] == 0) {
            current[a[i]] = 1;
            have++;
        }

        if (have == mex) {
            segments++;
            have = 0;
            for (ll j = 0; j < mex; j++) {
                current[j] = 0;
            }
        }
    }

    return segments >= k;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans;
    ll l = 0, r = n;
    while (l <= r) {
        ll mex = (l + r) / 2;
        if (ok(a, k, mex)) {
            ans = mex;
            l = mex + 1;
        } else {
            r = mex - 1;
        }
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