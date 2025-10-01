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
    vector<vector<int>> a(n);
    int mx_col = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> tmp(k);
        for (int j = 0; j < k; j++) cin >> tmp[j];
        a[i] = tmp;
        mx_col = max(mx_col, k);
    }

    vector<vector<int>> best(mx_col + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            best[j].push_back(i);
        }
    }

    vector<int> pos(n);

    for (int i = mx_col - 1; i >= 0; i--) {
        sort(best[i].begin(), best[i].end(), [&](int first, int second) {
            int size_f = a[first].size();
            int size_s = a[second].size();
            if (i >= size_f) return false;
            if (i >= size_s) return true;
            if (a[first][i] != a[second][i]) return a[first][i] < a[second][i];
            return pos[first] < pos[second];
        });
        for (int j = 0; j < best[i].size(); j++) pos[best[i][j]] = j;
    }

    vector<int> grid;
    int ptr = 0;
    while (ptr < mx_col) {
        for (auto i : best[ptr]) {
            grid.push_back(i);
            ptr = a[i].size();
            break;
        }
    }

    for (int col = 0; col < mx_col; col++) {
        for (auto i : grid) {
            if (col < a[i].size()) {
                cout << a[i][col] << " ";
                break;
            }
        }
    }
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