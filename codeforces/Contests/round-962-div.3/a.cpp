#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}
 
void solve() {
    ll n; cin >> n;
    ll ans = 0;
    ans = n / 4;
    if (n % 4 != 0) ans++;
    cout << ans << endl;
} 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int t; cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}