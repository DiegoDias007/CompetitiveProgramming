// https://codeforces.com/contest/2055/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll sum_row(vector<vector<ll>>& a, ll m, ll row) {
    ll sum = 0;
    for (ll j = 0; j < m; j++) {
        sum += a[row][j];
    }
    return sum;
}

ll sum_column(vector<vector<ll>>& a, ll n, ll col) {
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
        sum += a[i][col];
    }
    return sum;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<ll>> a(n, vector<ll>(m));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    ll row = 0, col = 0;
    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == 'D') {
            a[row][col] = -sum_row(a, m, row);
            row++;
        } else {
            a[row][col] = -sum_column(a, n, col);
            col++;
        }
    }

    a[row][col] = -sum_row(a, m, row);

    for (ll i = 0; i < n; i++) assert(sum_row(a, m, i) == 0);
    for (ll j = 0; j < m; j++) assert(sum_column(a, n, j) == 0);

    for (ll i = 0; i < n; i++) {
        print_vec(a[i]);
    }
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