#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> p(n, -1e9), s(n, -1e9);
    for (int i = 1; i < n; i++) p[i] = max(p[i - 1], a[i - 1] + (i - 1));
    for (int i = n - 2; i >= 0; i--) s[i] = max(s[i + 1], a[i + 1] - (i + 1));

    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, p[i] + s[i] + a[i]);
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