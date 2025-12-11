#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int MOD = 1e9 + 7;

struct SegTree {
    int n;
    vector<int> t;

    void init(vector<int>& a) {
        this->n = a.size();
        t.assign(4 * n, 0);
        build(a, 0, 0, n - 1);
    }

    void build(vector<int>& a, int i, int l, int r) {
        if (l == r) {
            t[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, 2*i + 1, l, m);
        build(a, 2*i + 2, m + 1, r);
        t[i] = (t[2*i + 1] + t[2*i + 2]) % MOD;
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    int query(int i, int cl, int cr, int l, int r) {
        if (max(l, cl) > min(r, cr)) return 0;
        if (l <= cl && cr <= r) return t[i];
        int m = (cl + cr) / 2;
        int left = query(2*i + 1, cl, m, l, r);
        int right = query(2*i + 2, m + 1, cr, l, r);
        return (left + right) % MOD;
    }

    void update(int i, int v) {
        update(v, i, 0, 0, n - 1);
    }

    void update(int v, int pos, int i, int l, int r) {
        if (l == r) {
            t[i] = v;
            return;
        }

        int m = (l + r) / 2;
        if (pos <= m) update(v, pos, 2*i + 1, l, m);
        else update(v, pos, 2*i + 2, m + 1, r);
        t[i] = (t[2*i + 1] + t[2*i + 2]) % MOD;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b = a;
    sort(b.begin(), b.end());

    map<int, int> pos;
    int prev = -1;
    for (int i = 0; i < n; i++) {
        if (b[i] != prev) {
            prev = b[i];
            pos[b[i]] = i;
        }
    }

    vector<int> dp(n);
    map<int, int> shift;

    SegTree seg;
    seg.init(dp);

    for (int i = 0; i < n; i++) {
        int p = pos[a[i]];
        int s = shift[a[i]];
        dp[p + s] = 1;
        shift[a[i]]++;
        if (p > 0) {
            int q = seg.query(0, p - 1);
            dp[p + s] = (dp[p + s] + q) % MOD;
        }
        seg.update(p + s, dp[p + s]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans = (ans + dp[i]) % MOD;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}