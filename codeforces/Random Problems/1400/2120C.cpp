// https://codeforces.com/contest/2120/problem/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll mx_sum = (1 + n) * n / 2;
    ll mn_sum = n;
    if (mx_sum < m || mn_sum > m) {
        cout << -1 << endl;
        return;
    }

    ll total_sum = n;
    vector<ll> a(n, 1);
    vector<int> not_used(n + 1, true);
    not_used[1] = false;
    for (int i = 0; i < n; i++) {
        ll l = 1, r = n - i;
        ll best = 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll p_sum = total_sum + mid - 1;
            if (p_sum <= m) {
                l = mid + 1;
                best = mid;
            } else {
                r = mid - 1;
            }
        }
        total_sum += best - 1;
        a[i] = best;
        not_used[best] = false;
    }

    vector<ll> nodes;
    for (int node = 1; node <= n; node++) if (not_used[node]) nodes.push_back(node);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i - 1] != 1) break;
        a[i] = nodes.back();
        nodes.pop_back();
    }

    cout << a[0] << endl;
    for (int i = 0; i < n - 1; i++) {
        cout << a[i] << " " << a[i + 1] << endl;
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