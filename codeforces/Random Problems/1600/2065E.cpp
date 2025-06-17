// https://codeforces.com/contest/2065/problem/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int mn = abs(n - m);
    int mx = max(n, m);
    bool ok = mn <= k && k <= mx;
    if (!ok) {
        cout << -1 << endl;
        return;
    }

    int cnt_0 = n, cnt_1 = m;
    vector<char> a(n + m);
    bool cur_char = n < m;
    for (int i = 0; i < k; i++) {
        a[i] = '0' + cur_char;
        if (cur_char == 0) {
            cnt_0--;
        } else {
            cnt_1--;
        }
    }

    int idx = k + abs(cnt_1 - cnt_0);
    if (idx != k) cur_char = !cur_char;
    for (int i = k; i < idx; i++) {
        a[i] = '0' + cur_char;
        if (cur_char == 0) {
            cnt_0--;
        } else {
            cnt_1--;
        }
    }

    cur_char = !cur_char;
    for (int i = idx; i < n + m; i++) {
        a[i] = '0' + cur_char;
        cur_char = !cur_char;
    }

    for (int i = 0; i < n + m; i++) cout << a[i];
    cout << endl;
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