// https://codeforces.com/contest/2046/problem/B

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

    vector<int> mn(n + 1, 2e9);
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(mn[i + 1], a[i + 1]);
    }

    int mn_changed = 2e9;
    for (int i = 0; i < n; i++) {
        int global_mn = min(mn_changed, mn[i]);
        if (global_mn < a[i]) {
            a[i]++;
            mn_changed = min(mn_changed, a[i]);
        }
    }
    sort(a.begin(), a.end());
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