// https://codeforces.com/contest/2061/problem/D

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void dfs(map<int, int>& a, int cur, bool& possible) {
    if (cur == 0) {
        possible = false;
        return;
    }

    if (a[cur] > 0) {
        a[cur]--;
        return;
    }

    dfs(a, cur / 2, possible);
    if (!possible) {
        return;
    }
    dfs(a, cur / 2 + (cur % 2 == 1 && cur != 1), possible); 
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        a[cur]++;
    }

    bool possible = true;
    for (int i = 0; i < m; i++) {
        int cur;
        cin >> cur;
        dfs(a, cur, possible);
    }

    for (auto [value, cnt] : a) {
        possible &= cnt == 0;
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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