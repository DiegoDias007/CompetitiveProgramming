#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    ll even_sum = 0;
    set<ll> odd;
    for (ll i = 0; i < n; i++) {
        
        if (odd.find(a[i]) != odd.end()) {
            even_sum += 2 * a[i];
            odd.erase(a[i]);
        } else {
            odd.insert(a[i]);
        }

        if (i <= 1) continue;
        
        ll best = even_sum;
        ll sz = odd.size();
        if (sz != 0) {
            ll mx = *(odd.rbegin());
            best += mx;
            if (sz >= 2) {
                odd.erase(mx);
                ll s_mx = *(odd.rbegin());
                best += s_mx;
                odd.insert(mx);
            }
        }

        bool ok = a[i] < best - a[i];
        if (!ok) continue;
        ans = max(ans, best);        
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