// https://codeforces.com/problemset/problem/2117/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool check(int x, int idx, vector<int>& seen_same, vector<int>& seen_op) {
    int dist_same = seen_same[x] - idx;
    return (dist_same) >= 2 || (seen_op[x] != -1);
}

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

    int ans = 0;
    bool possible = false;
    vector<int> seen_a(n + 1, -1), seen_b(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        possible |= a[i] == b[i];
        possible |= check(b[i], i, seen_a, seen_b);
        possible |= check(a[i], i, seen_b, seen_a);
        if (possible) {
            ans = i + 1;
            break;
        }
        if (seen_a[a[i]] == -1) seen_a[a[i]] = i;
        if (seen_b[b[i]] == -1) seen_b[b[i]] = i;
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