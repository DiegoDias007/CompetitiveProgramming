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
    vector<int> a(n), b(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, pair<int, int>>> ops;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) continue;
        ok &= mp.count(b[i]) && a[i] < b[i];
        if (!ok) break;
        ops.push_back({b[i], {i + 1, mp[b[i]] + 1}});
    }

    if (!ok) {
        cout << -1 << endl;
    } else {
        cout << ops.size() << endl;
        sort(ops.begin(), ops.end());
        for (auto op : ops) {
            cout << op.second.first << " " << op.second.second << endl;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    int cs = 1;
    while (t--) {
        cout << "Case #" << cs++ << ": ";
        solve();
    }
    
    return 0;
}