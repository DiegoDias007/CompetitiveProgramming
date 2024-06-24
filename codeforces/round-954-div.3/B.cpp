#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
void print_vec(const vector<int>& vec) {
    for(size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if(i != vec.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
}
 
template <typename K, typename V>
void print_map(const map<K, V>& m) {
    cout << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->first << ": " << it->second;
        if (next(it) != m.end()) {
            cout << ", ";
        }
    }
    cout << "}" << endl;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int current = matrix[i][j];
            int left = 0, right = 0, top = 0, bottom = 0;
            if (j - 1 >= 0) {
                left = matrix[i][j - 1];
            } if (j + 1 < m) {
                right = matrix[i][j + 1];
            } if (i - 1 >= 0) {
                top = matrix[i - 1][j];
            } if (i + 1 < n) {
                bottom = matrix[i + 1][j];
            }
 
            if (( left == 0 || current > left) && ( right == 0 || current > right) && ( top == 0 || current > top) && ( bottom == 0 || current > bottom)) {
                int value = max(left, max(right, max(top, bottom)));
                matrix[i][j] = value;
            }
 
            cout << matrix[i][j] << " ";
        }
 
        cout << endl;
    }
 
 
 } 
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int tests;
    cin >> tests;
    while (tests--) {
        solve();
    }
 
    return 0;
}