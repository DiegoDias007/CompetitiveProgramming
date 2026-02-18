#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

int bad(int x1, int x2) {
    return (x1 == 7 - x2) || x1 == x2;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    vector<int> fixed(n);
    for (int i = 1; i < n; i++) {
        if (fixed[i - 1]) continue;
        if (bad(a[i - 1], a[i])) {
            fixed[i] = true;
            ans++;
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