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
    int need = n, idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] != need) {
            idx = i;
            break;
        }
        need--;
    }

    if (idx == -1) {
        print_vec(a);
        return;
    }

    int need_idx = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == need) {
            need_idx = i;
            break;
        }
    }

    reverse(a.begin() + idx, a.begin() + need_idx + 1);
    print_vec(a);
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