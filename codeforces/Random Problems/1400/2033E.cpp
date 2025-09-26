// https://codeforces.com/problemset/problem/2033/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int ans;

void dfs(vector<int>& a, vector<int>& vis, int i, int size, int n) {
    if (vis[i]) {
        ans += size / 2 - 1;
        return;
    }
    
    vis[i] = true;
    int child = a[i];
    dfs(a, vis, child, size + 1, n);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<int> vis(n);
    ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != i && !vis[i]) {
            dfs(a, vis, i, 1, n);
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