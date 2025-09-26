// https://codeforces.com/contest/2098/problem/B

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 1 && k == 0) {
        cout << 1 << endl;
        return;
    }

    int l = 2e9, r = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) {
        int cnt_left = i;
        int cnt_right = n - i - 2;
        if (abs(cnt_left - cnt_right) <= k) {
            l = min(l, a[i]);
            r = max(r, a[i + 1]);
        }
    }
    cout << r - l + 1 << endl;
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