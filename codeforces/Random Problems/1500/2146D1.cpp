// https://codeforces.com/contest/2146/problem/D1

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int get_msb(int x) {
    for (int i = 29; i >= 0; i--) {
        int bit = 1 << i;
        if (x & bit) return i;
    }
    assert(false);
}

void solve() {
    int l, r;
    cin >> l >> r;
    if (r == 0) {
        cout << 0 << endl;
        cout << 0 << endl;
        return;
    }
    vector<int> seen(r + 1);
    int r_msb = get_msb(r);
    vector<int> a(r + 1);
    for (int x = r; x >= 0; x--) {
        int mask = (1 << (r_msb + 1)) - 1;
        int y = x ^ mask;
        while (y > r || seen[y]) {
            int y_msb = get_msb(y);
            mask = (1 << y_msb) - 1;
            y &= mask;
        }
        a[x] = y;
        seen[y] = true;
    }
    ll ans = 0;
    for (int i = 0; i <= r; i++) ans += a[i] | i;
    assert(ans == 1ll * r * (r + 1));
    cout << ans << endl;
    print_vec(a);
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