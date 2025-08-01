// https://codeforces.com/problemset/problem/2059/C

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
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> possible(n);

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = n - 1; j >= 1; j--) {
            if (a[i][j] != 1) break;
            sum++;
            possible[i] = sum;
        }
    }

    int ans = 0;
    int l = 1, r = n;
    while (l <= r) {
        int mex = (l + r) / 2;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            cnt[min(possible[i], mex - 1)]++;
        }

        for (int i = mex - 1; i >= 1; i--) {
            if (cnt[i] >= 1) {
                cnt[i - 1] += cnt[i] - 1;
                cnt[i] = 1;
            }
        }

        bool ok = true;
        for (int i = 0; i < mex; i++) ok &= cnt[i] >= 1;
        if (ok) {
            l = mex + 1;
            ans = mex;
        } else {
            r = mex - 1;
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