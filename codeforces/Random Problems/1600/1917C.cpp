// https://codeforces.com/problemset/problem/1917/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n + 1), v(k + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= k; i++) {
        cin >> v[i];
    }

    int j_idx = 0;
    int ans = 0;
    int mx_idx = min(100*n, d - 1);
    for (int j = 0; j <= mx_idx; j++, j_idx++) {
        if (j_idx > k) j_idx = 1;
        int cnt_ok = 0;
        for (int i = 1; i <= n; i++) {
            a[i] += i <= v[j_idx];
            cnt_ok += a[i] == i;
        }

        int cur_score = cnt_ok + (d - j - 1) / 2;
        ans = max(ans, cur_score);
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