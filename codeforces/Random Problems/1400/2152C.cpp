#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> ps(n + 1);
    for (int i = 1; i <= n; i++) {
        ps[i] = ps[i - 1] + (a[i - 1] == 0);
    }

    vector<int> ps0(n + 1);
    for (int i = 2; i <= n; i++) {
        ps0[i] = ps0[i - 1] + (a[i - 1] == a[i - 2]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int cnt_0 = ps[r + 1] - ps[l];
        int cnt_1 = r - l + 1 - cnt_0;
        if (cnt_0 % 3 || cnt_1 % 3) {
            cout << -1 << endl;
            continue;
        }

        int c0 = cnt_0 / 3;
        int c1 = cnt_1 / 3;
        int ans = c0 + c1;

        int cnt = ps0[r + 1] - ps0[l];
        if (l > 0 && a[l] == a[l - 1]) cnt--;
        ans += cnt == 0;
        
        cout << ans << endl;
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