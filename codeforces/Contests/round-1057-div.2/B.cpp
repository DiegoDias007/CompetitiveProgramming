#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    vector<int> bit_cnt(31);
    for (int b = 0; b < 31; b++) {
        int bit = 1 << b;
        for (int i = 0; i < 3; i++) {
            if (a[i] & bit) bit_cnt[b]++;
        }
    }

    bool ok = true;
    for (int i = 0; i < 31; i++) {
        if (bit_cnt[i] == 0) continue;
        ok &= bit_cnt[i] % 2 == 1;
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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