#include <bits/stdc++.h>

#define endl "\n"
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> perm(2*n + 1);
    vector<int> need(2*n + 1, 1);
    for (int i = 1; i <= n; i++) {
        perm[i + i] = a[i - 1][i - 1];
        need[a[i - 1][i - 1]] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            perm[i + j] = a[i - 1][j - 1];
            need[a[i - 1][j - 1]] = 0;
        }
    }

    int p = 1;
    for (int i = 1; i <= 2 * n; i++) {
        if (perm[i] == 0) {
            while (need[p] == 0) {
                p++;
            }
            perm[i] = p;
            need[p] = 0;
        }

        cout << perm[i] << " ";
    }

    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }

    return 0;
}