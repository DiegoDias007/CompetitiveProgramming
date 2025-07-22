// https://codeforces.com/problemset/problem/2070/C

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
    string s;
    cin >> s;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = -1;
    int l = 0, r = 1e9 + 5;
    while (l <= r) {
        int want = (l + r) / 2;
        int cur_k = 0;
        bool painting = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (a[i] > want) {
                    painting = false;
                }
            } else if (a[i] > want && !painting) {
                painting = true;
                cur_k++;
            }
        }
        bool ok = cur_k <= k;
        if (ok) {
            ans = want;
            r = want - 1;
        } else {
            l = want + 1;
        }
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