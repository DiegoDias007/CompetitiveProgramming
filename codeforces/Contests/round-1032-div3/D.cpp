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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> ops;    
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j + 1] < a[j]) {
                swap(a[j], a[j + 1]);
                ops.push_back({1, j + 1});
            }
        }
    }

    for (int i = n - 1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (b[j + 1] < b[j]) {
                swap(b[j], b[j + 1]);
                ops.push_back({2, j + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            swap(a[i], b[i]);
            ops.push_back({3, i + 1});
        }
    }

    cout << ops.size() << endl;
    for (auto op : ops) {
        cout << op.first << " " << op.second << endl;
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