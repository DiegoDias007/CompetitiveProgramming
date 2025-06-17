// https://codeforces.com/contest/2082/problem/B

#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int calc_mx(int x, int n, int m) {
    for (int i = 0; i < n; i++) {
        x /= 2;
    }

    for (int i = 0; i < m; i++) {
        bool flag = x % 2;
        x /= 2;
        x += flag;
        
    }
    return x;
}

int calc_mn(int x, int n, int m) {
    for (int i = 0; i < m; i++) {
        bool flag = x % 2;
        x /= 2;
        x += flag;
    }

    for (int i = 0; i < n; i++) {
        bool flag = x % 2;
        x /= 2;
    }
    return x;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    n = min(n, 32);
    m = min(m, 32);
    cout << calc_mn(x, n, m) << " " << calc_mx(x, n, m) << endl;
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