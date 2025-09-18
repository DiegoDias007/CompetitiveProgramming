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
    vector<int> seen(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        seen[a[i]] = true;
    }

    int p = n;
    for (int i = 0; i < n; i++) {
        if (a[i] != 0) continue;
        while (seen[p]) p--;
        a[i] = p;
        seen[p] = true;
    }

    bool done = true;
    int l = n + 1, r = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != i + 1) {
            l = min(l, a[i]);
            r = max(r, a[i]);
            done = false;
        }
    }

    if (done) cout << 0 << endl;
    else cout << r - l + 1 << endl;
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