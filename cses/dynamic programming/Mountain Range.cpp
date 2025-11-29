#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

struct SegTree {
    int n;
    vector<int> t;

    void init(vector<int>& a, int n) {
        this->n = n;
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
        t[i] = max(t[2*i + 1], t[2*i + 2]);
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
        return max(left, right);
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
        t[i] = max(t[2*i + 1], t[2*i + 2]);
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> left(n), right(n);
    vector<int> stk = {-1};
    for (int i = 0; i < n; i++) {
        while (stk.back() != -1 && a[i] > a[stk.back()]) stk.pop_back();
        left[i] = stk.back() + 1;
        stk.push_back(i);
    }

    stk = {n};
    for (int i = n - 1; i >= 0; i--) {
        while (stk.back() != n && a[i] > a[stk.back()]) stk.pop_back();
        right[i] = stk.back() - 1;
        stk.push_back(i);
    }

    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) b[i] = {a[i], i};
    sort(b.begin(), b.end());

    
    // dp[i]: maior numero de montanhas que podemos visitar se
    // comecarmos no idx i
    vector<int> dp(n);

    SegTree seg;
    seg.init(dp, n);
    
    for (int k = 0; k < n; k++) {
        int ai = b[k].first, i = b[k].second;
        int l = left[i], r = right[i];
        
        int mx = seg.query(l, r);
        dp[i] = mx + 1;
        seg.update(i, dp[i]);
    }

    int ans = 0;
    for (auto v : dp) ans = max(ans, v);
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
