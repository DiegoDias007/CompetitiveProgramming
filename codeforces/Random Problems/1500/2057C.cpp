// https://codeforces.com/problemset/problem/2057/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int l, r;
    cin >> l >> r;

    int a = r, b = 0, c = l;
    int start_bit = -1;
    for (int i = 29; i >= 0; i--) {
        int bit = 1 << i;
        if ((r & bit) && (l & bit)) {
            b |= bit;
            c |= bit;
        }

        if ((r & bit) && !(l & bit)) {
            b |= bit;
            c |= bit - 1;
            break; 
        }
    }
    
    while (a == b || a == c) a--;
    cout << a << " " << b << " " << c << endl;
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