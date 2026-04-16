#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int x, y;
    cin >> x >> y;
    int sz = x + y;
    int mn_even = sz % 2 == 1 ? 0 : 1, mx_even = sz / 2;
    bool impossible = x > mx_even || x < mn_even;
    if (impossible) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int path_size = 2 * x + (sz % 2 ? 1 : -1);
    int cur = 2;
    for (int i = 1; i < path_size; i++) {
        cout << cur - 1 << " " << cur << endl;
        cur++;
    }

    while (cur <= sz) {
        cout << 1 << " " << cur << endl;
        cur++;
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