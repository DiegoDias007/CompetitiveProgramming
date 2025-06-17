#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
struct custom_hash {static uint64_t splitmix64(uint64_t x) {x += 0x9e3779b97f4a7c15;x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x = (x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31);}size_t operator()(uint64_t x) const {static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM);}};
 
void solve() {
    ll n, d, k;
    cin >> n >> d >> k;
    vector<ll> diff(n + 2);
    for (ll i = 0; i < k; i++) {
        ll l, r;
        cin >> l >> r;
        diff[max(1ll, l - d + 1)]++;
        diff[r + 1]--;
    }
 
    ll sum = 0;
    ll bro = 0, mom = 1e9;
    ll ind1 = 1, ind2 = 1;
    for (ll i = 1; i <= n - d + 1; i++) {
        sum += diff[i];
 
        if (sum > bro) { 
            bro = sum;
            ind1 = i;
        }
 
        if (sum < mom) {
            mom = sum;
            ind2 = i;
        }
 
    }
 
    cout << ind1 << " " << ind2 << endl;
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