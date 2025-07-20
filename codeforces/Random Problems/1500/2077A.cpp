// https://codeforces.com/problemset/problem/2077/A

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
    vector<ll> a(2*n);
    for (int i = 0; i < 2*n; i++) {
        cin >> a[i];
    }
    
    sort(a.rbegin(), a.rend());
    ll x = 0;
    vector<ll> ans(2*n + 1);
    int ptr = 0;
    for (int i = 0; i < n + 1; i++) {
        ans[ptr] = a[i];
        ptr += 2;
        x += a[i];
    }

    ptr = 1;
    for (int i = n + 1; i < 2*n; i++) {
        ans[ptr] = a[i];
        ptr += 2;
        x -= a[i];
    }

    ans[2*n - 1] = x;
    print_vec(ans);
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