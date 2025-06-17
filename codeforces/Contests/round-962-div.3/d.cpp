#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
template <typename K, typename V> void print_map(const map<K, V>& m) {  cout << "{"; for (auto it = m.begin(); it != m.end(); ++it) { cout << it->first << ": " << it->second; if (next(it) != m.end()) { cout << ", ";}}cout << "}" << endl;}

int n, x;

void solve() {
    cin >> n >> x;
    ll ans = 0;
    for (int a = 1; a < x - 1; a++) {
        for (int b = 1; a * b < n; b++) {
            int c1 = x - a - b;
            int c2 = (n - a * b) / (a + b);
            int c = min(c1, c2);
            if (c <= 0) break;
            ans += c;
        }
    }

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
