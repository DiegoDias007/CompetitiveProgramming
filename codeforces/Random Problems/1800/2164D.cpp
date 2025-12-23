#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

int fnd(vector<int>& a, int x) {
    int y = 1e9 + 10;
    int l = 0, r = a.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x) {
            y = a[mid];
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return y;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    
    vector<vector<int>> a(26);
    for (int i = 0; i < n; i++) {
        int c = s[i] - 'a';
        a[c].push_back(i);
    }

    map<int, int> mp;
    bool ok = true;
    int mn_left = 1e9;
    for (int i = n - 1; i >= 0; i--) {
        int c = t[i] - 'a';
        
        while (!a[c].empty() && a[c].back() > i) a[c].pop_back();

        int j = fnd(a[c], mn_left);
        int d = i - j;
        
        ok &= d <= k && j <= mn_left;
        if (!ok) break;
        
        mn_left = j;
        mp[j] = max(mp[j], i);
    }

    if (!ok) {
        cout << -1 << endl;
        return;
    }

    int d = 0;
    vector<pair<int, int>> b;
    for (auto [l, r]: mp) {
        b.push_back({l, r});
        d = max(d, r - l);
    }

    cout << d << endl;

    for (int time = 0; time < d; time++) {
        string p = s;
        int m = b.size();
        for (int i = 0; i < m; i++) {
            int l = b[i].first, r = b[i].second;
            if (l == r) continue;
            p[l + 1] = s[l];
            b[i].first++;
        }
        cout << p << endl;
        s = p;
    }
    assert(s == t);
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