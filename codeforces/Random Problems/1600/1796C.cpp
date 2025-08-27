// https://codeforces.com/contest/1796/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool is_valid_branch(int x, int mx_size, int r) {
    int tmp_x = x;
    int remaining = mx_size - 2;
    while (remaining) {
        tmp_x *= 2;
        remaining--;
    }
    return tmp_x <= r;
}

void solve() {
    int l, r;
    cin >> l >> r;

    int tmp_l = l;
    int mx_size = 0;
    while (tmp_l <= r) {
        tmp_l *= 2;
        mx_size++;
    }

    if (mx_size == 1) {
        cout << 1 << " " << r - l + 1 << endl;
        return;
    }

    int ways = 0;

    int best_l = -1;
    int left = l, right = 2*l;
    while (left <= right) {
        int cur_l = (left + right) / 2;
        if (is_valid_branch(2*cur_l, mx_size, r)) {
            best_l = cur_l;
            left = cur_l + 1;
        } else {
            right = cur_l - 1;
        }
    }

    if (best_l != -1) ways += best_l - l + 1;

    best_l = -1;
    left = l, right = 2*l;
    while (left <= right) {
        int cur_l = (left + right) / 2;
        if (is_valid_branch(cur_l*3, mx_size, r)) {
            best_l = cur_l;
            left = cur_l + 1;
        } else {
            right = cur_l - 1;
        }
    }

    if (best_l != -1) ways += (best_l - l + 1) * (mx_size - 1);
    
    cout << mx_size << " " << ways << endl;
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