// https://codeforces.com/problemset/problem/2129/B

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

    for (int i = 0; i < n; i++) {
        int cnt1 = 0, cnt2 = 0;        
        for (int l = i - 1; l >= 0; l--) {
            cnt1 += a[l] > a[i];
            cnt2 += a[l] > (2*n - a[i]);
        }
        for (int r = i + 1; r < n; r++) {
            cnt1 += a[r] < a[i];
            cnt2 += a[r] < (2*n - a[i]);
        }
        if (cnt2 < cnt1) a[i] = 2*n - a[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans += a[i] > a[j];
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