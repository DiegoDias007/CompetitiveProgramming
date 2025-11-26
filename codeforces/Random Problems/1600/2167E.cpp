#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    set<int> ipt;
    for (int i = 0; i < n; i++) {
        int y;
        cin >> y;
        ipt.insert(y);
    }
    vector<int> a;
    for (auto v : ipt) a.push_back(v);
    n = a.size();

    auto place = [&](vector<int>& cur, int pos, int mx) {
        while (pos <= x && pos <= mx && cur.size() < k) {
            cur.push_back(pos);
            pos++;
        }
    };

    auto ok = [&](vector<int>& cur, int mid) -> bool {
        place(cur, 0, a[0] - mid);
        place(cur, a.back() + mid, x);
        for (int i = 0; i < n - 1; i++) {
            int pos = a[i] + mid;
            place(cur, pos, a[i + 1] - mid);
        }
        return cur.size() == k;
    };

    vector<int> best(k);
    for (int i = 0; i < k; i++) best[i] = i;

    int l = 1, r = x;
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<int> cur;
        if (ok(cur, mid)) {
            best = cur;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    print_vec(best);
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