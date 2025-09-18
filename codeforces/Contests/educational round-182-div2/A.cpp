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

    for (int l = 0; l < n - 2; l++) {
        for (int r = l + 1; r < n - 1; r++) {
            int s1 = 0, s2 = 0, s3 = 0;
            for (int i = 0; i < n; i++) {
                if (i <= l) s1 += a[i];
                else if (i <= r) s2 += a[i];
                else s3 += a[i];
            }

            int m1 = s1 % 3, m2 = s2 % 3, m3 = s3 % 3;
            bool ok = m1 != m2 && m1 != m3 && m2 != m3;
            ok |= m1 == m2 && m1 == m3 && m2 == m3;
            if (ok) {
                cout << l + 1 << " " << r + 1 << endl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << endl;
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