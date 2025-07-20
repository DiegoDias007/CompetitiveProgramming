// https://codeforces.com/contest/2106/problem/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    if (m == 1) {
        bool flag = false;
        for (int i = 0; i < n; i++) {
            flag |= a[i] >= b[0];
        }
        if (flag) cout << 0 << endl;
        else cout << b[0] << endl;
        return;
    }

    vector<int> pref(m, 1e9), suf(m, -1);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[p]) {
            pref[p] = i;
            p++;
        }

        if (p == m) break;
    }

    p = m - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] >= b[p]) {
            suf[p] = i;
            p--;
        }

        if (p == -1) break;
    }

    int ans = 2e9;
    for (int i = 0; i < m; i++) {
        bool ok = false;
        if (i == 0) ok |= suf[i + 1] >= 0;
        else if (i == m - 1) ok |= pref[i - 1] <= n - 1; 
        else ok |= pref[i - 1] < suf[i + 1];
        if (ok) {
            ans = min(ans, b[i]);
        }
    }

    p = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[p]) {
            p++;
        }
        if (p == m) {
            ans = 0;
            break;
        }
    }

    if (ans == 2e9) cout << -1 << endl;
    else cout << ans << endl;
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