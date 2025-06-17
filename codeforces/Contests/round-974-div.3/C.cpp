#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
 
void solve() {
    ll n;
    cin >> n;
    vector<double> a(n);
    double sum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
 
    sort(a.begin(), a.end());
    ll l = 0, r = 10e15;
    ll ans = 10e15;
    bool found = false;
    while (l <= r) {
        ll x = (l + r) / 2;
        double wealth = (double(sum) + double(x)) / (2.0 * double(n));
        a.back() += double(x);
        int index = n / 2;
        double check = a[index];
        if (check < wealth) {
            ans = min(ans, x);
            r = x - 1;
            found = true;
        } else {
            l = x + 1;
        }
        a.back() -= double(x);
    }
 
    if (!found) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    
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
