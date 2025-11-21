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
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> mx(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        mx[i] = max(mx[i + 1], a[i + 1]);
    }

    vector<int> comp;
    vector<vector<int>> adj(n + 1);
    int mn = 1e9, who;
    int gmn = -1;
    for (int i = 0; i < n; i++) {
        mn = min(mn, a[i]);

        comp.push_back(a[i]);

        // novo componente
        if (a[i] > mx[i]) {
            if (a[i] < gmn) {
                cout << "NO" << endl;
                return;
            }

            int m = comp.size();
            for (int j = m - 2; j >= 0; j--) {
                adj[a[i]].push_back(comp[j]);
            }

            if (gmn != -1) adj[a[i]].push_back(gmn);
            
            if (gmn == -1) gmn = mn;
            else gmn = min(gmn, mn);
            mn = 1e9;
            comp = {};
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
        for (auto c : adj[i]) {
            cout << i << " " << c << endl;
        }
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