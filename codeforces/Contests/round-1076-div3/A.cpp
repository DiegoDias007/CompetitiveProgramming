#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        sum += ai;
    }

    int dif = s - sum;
    bool ok = dif >= 0 && (dif % x == 0);
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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