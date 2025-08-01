// https://codeforces.com/problemset/problem/2084/D

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

    vector<int> a(n);
    int mex = min(n - m*k, n / (m + 1));
    int mx_size = max(k, mex);
    int cur_value = 0;
    int cnt_mx = 0;
    for (int i = 0; i < n; i++) {
        if (cur_value >= mx_size) {
            cur_value = 0;
        }
        cnt_mx += cur_value % mex == mex - 1;
        a[i] = cur_value % mex;
        cur_value++;
    }
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