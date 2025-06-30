// https://codeforces.com/contest/2043/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void sums_interval(vector<int>& a, set<int>& ans, int l, int r) {
    int mn_sum = 0, mx_sum = 0;
    for (int i = l; i < r; i++) {
        if (a[i] != -1 && a[i] != 1) {
            continue;
        }

        mn_sum += a[i];
        mx_sum += a[i];

        mn_sum = min(mn_sum, 0);
        mx_sum = max(mx_sum, 0);

        ans.insert(mn_sum);
        ans.insert(mx_sum);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int idx = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1 && a[i] != 1) {
            idx = i;
        }
    }

    set<int> ans = {0};
    if (idx == -1) {
        sums_interval(a, ans, 0, n);
    } else {
        sums_interval(a, ans, 0, idx);
        sums_interval(a, ans, idx + 1, n);
        int sum_left = 0, mn_left = 0, mx_left = 0;
        for (int i = idx - 1; i >= 0; i--) {
            sum_left += a[i];
            mn_left = min(mn_left, sum_left);
            mx_left = max(mx_left, sum_left);
        }

        int sum_right = 0, mn_right = 0, mx_right = 0;
        for (int i = idx + 1; i < n; i++) {
            sum_right += a[i];
            mn_right = min(mn_right, sum_right);
            mx_right = max(mx_right, sum_right);
        }

        int mn = mn_left + mn_right, mx = mx_left + mx_right;
        for (int value = mn; value <= mx; value++) {
            ans.insert(value + a[idx]);
        }
    }
    
    cout << (int)ans.size() << endl;
    for (auto value : ans) {
        cout << value << " ";
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