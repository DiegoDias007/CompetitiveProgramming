#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> open_idx(n+1, -1), open(n+1);
    for (int i = n - 1; i >= 0; i--) {
        open[i] = open[i+1] + (s[i] == '(');
        open_idx[i] = open_idx[i+1];
        if (s[i] == '(') open_idx[i] = i;
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        int j = open_idx[i];
        if (s[i] == '(' || j == -1) continue;
        int sz = j - i;
        if (open[j] - 1 >= sz) ans = max(ans, n - 2*sz);
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