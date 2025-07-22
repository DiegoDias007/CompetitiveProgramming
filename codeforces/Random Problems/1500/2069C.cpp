// https://codeforces.com/problemset/problem/2069/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(4);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            cnt[a[i]] += cnt[a[i]];
            cnt[a[i]] %= MOD;
        }
        cnt[a[i]] += cnt[a[i] - 1];
        cnt[a[i]] %= MOD;
    }
    cout << cnt[3] << endl;
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