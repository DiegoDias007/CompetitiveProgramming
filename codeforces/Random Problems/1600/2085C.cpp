// https://codeforces.com/problemset/problem/2085/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int x, y;
    cin >> x >> y;
    if (x == y) {
        cout << -1 << endl;
        return;
    }

    if (x < y) {
        swap(x, y);
    }

    int ans;
    for (int bit = 29; bit >= 0; bit--) {
        bool x_has_bit = (1 << bit) & x;
        if (x_has_bit) {
            int new_x = 1 << (bit + 1);
            ans = new_x - x;
            break; 
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