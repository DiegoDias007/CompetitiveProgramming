#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    n = 2*n;
    vector<int> a(n);
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    int ans = 0;
    int cnt_flag = 0, cnt_odd = 0;
    for (auto [_, c] : cnt) {
        if (c % 2 == 1) {
            cnt_odd++;
            continue;
        }

        bool flag = (c / 2) % 2 == 1;
        if (flag) ans += 2;
        else cnt_flag++;
    }
    ans += cnt_odd;
    if (cnt_flag % 2 == 0) ans += 2*cnt_flag;
    else ans += 2*(cnt_flag - 1) + 2*(cnt_odd >= 1); 
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