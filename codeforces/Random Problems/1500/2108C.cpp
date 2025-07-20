// https://codeforces.com/problemset/problem/2108/C

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
    vector<int> a_prev(n);
    for (int i = 0; i < n; i++) {
        cin >> a_prev[i];
    }

    int cnt = 0;
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a_prev[i] != a_prev[i - 1]) {
            a.push_back({a_prev[i], cnt});
            cnt++;
        }
    }

    sort(a.rbegin(), a.rend());

    int ans = 0;
    set<int> robots;
    for (int i = 0; i < cnt; i++) {
        int idx = a[i].second;

        if (robots.find(idx + 1) == robots.end() && robots.find(idx - 1) == robots.end()) {
            ans++;
        }

        robots.insert(idx);
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