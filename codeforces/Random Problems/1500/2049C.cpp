// https://codeforces.com/contest/2049/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (x % 2 != y % 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << i % 2 << " ";
        }
        if (n % 2 == 0) cout << 1;
        else cout << 2;
        cout << endl;
        return;
    }

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (i + x % 2) % 2;
    }
    if (n % 2 == 1) a.back() = 2;
    if (!(n % 2 == 1 && y == n)) {
        if (x == 1) a[y - 1] = 2;
        else a[x - 1] = 2;
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