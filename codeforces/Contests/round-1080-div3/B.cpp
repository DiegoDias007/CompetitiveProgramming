#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        int j = i + 1;
        int k = 2*j - 1;
        vector<int> idxs = {i};
        while (k < n) {
            idxs.push_back(k);
            if (a[k] == b[i]) break;
            j = k + 1;
            k = 2*j - 1;
        }
        if (k >= n || a[k] != b[i]) {
            ok = false;
            break;
        }
        int m = idxs.size();
        for (int l = m - 1; l >= 1; l--) swap(a[idxs[l]], a[idxs[l - 1]]);
    }
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