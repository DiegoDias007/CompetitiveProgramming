#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, x;
    cin >> n >> x;

    if (x == 0) {
        if (n == 1) cout << -1 << endl;
        else cout << n + 3*(n % 2) << endl;
        return;
    }

    if (x == 1) {
        if (n % 2 == 1) cout << n << endl;
        else cout << n + 3 << endl;
        return;
    }

    int bit_cnt = 0;
    for (int i = 30; i >= 0; i--) {
        int mask = 1 << i;
        if (x & mask) {
            bit_cnt++;
        }
    }

    if (bit_cnt >= n) {
        cout << x << endl;
        return;
    }
    
    int rem = n - bit_cnt;
    int ans = x + rem;
    if (rem % 2 == 1) ans++;
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