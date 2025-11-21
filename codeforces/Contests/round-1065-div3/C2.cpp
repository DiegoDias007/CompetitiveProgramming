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
    vector<int> a1(n), a2(n);
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a2[i];
    }

    for (int bit = 30; bit >= 0; bit--) {
        int mask = 1 << bit;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            if (a1[i] & mask) a[i] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (a2[i] & mask) b[i] = 1;
        }

        bool x = false, y = false;
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (x + y == 1) {
                x = false;
                y = false;
                continue;
            }
            if (i % 2 == 0) {
                x = true;
                y = false;
            } else {
                x = false;
                y = true;
            }
        }
        if (x == y) continue;
        else if (x) {
            cout << "Ajisai" << endl;
            return;
        } else {
            cout << "Mai" << endl;
            return;
        }
    }
    cout << "Tie" << endl;
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