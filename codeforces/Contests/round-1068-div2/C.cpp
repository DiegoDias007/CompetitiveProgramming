#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }

    b = a;
    for (auto x : a) {
        if (b.find(x) == b.end()) continue;
        for (int y = 2*x; y <= k; y += x) {
            if (a.find(y) == a.end()) {
                cout << -1 << endl;
                return;
            }

            if (b.find(y) != b.end()) b.erase(y);
        }
    }

    cout << b.size() << endl;
    for (auto x : b) cout << x << " ";
    cout << endl;
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