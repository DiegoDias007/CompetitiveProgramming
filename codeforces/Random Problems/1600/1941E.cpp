// https://codeforces.com/problemset/problem/1941/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> best(n);
    for (int i = 0; i < n; i++) {
        deque<pair<int, ll>> dq = {{0, 0}};
        for (int j = 1; j < m; j++) {
            while (!dq.empty() && j - dq.front().first - 1 > d) {
                dq.pop_front();
            }

            if (j == m - 1) {
                best[i] = dq.front().second + 2;
                break;
            }

            ll cur = dq.front().second + a[i][j] + 1;
            while (!dq.empty() && dq.back().second > cur) {
                dq.pop_back();
            }

            dq.push_back({j, cur});
        }
    }

    ll ans = 1e18;
    ll cur = 0;
    int l = 0;
    for (int r = 0; r < n; r++) {
        cur += best[r];
        while (r - l + 1 > k) {
            cur -= best[l];
            l++;
        }
        if (r - l + 1 == k) {
            ans = min(ans, cur);
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