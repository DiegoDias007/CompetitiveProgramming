// https://codeforces.com/contest/2026/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool ok(string&s, int n, int mid) {
    int need = 1;
    for (int i = n - 1; i >= mid + 1; i--) {
        if (s[i] == '1') need++;
        else need = max(1, need - 1);
    }
    
    return mid >= need;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (n <= 2) {
        cout << 1 << endl;
        return;
    }

    vector<int> idxs;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') idxs.push_back(i);
    }

    int m = idxs.size();
    int l = 0, r = m - 2;
    int best = m - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (ok(s, n, mid)) {
            r = mid - 1;
            best = mid;
        } else {
            l = mid + 1;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' || i < best) ans += i + 1;
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