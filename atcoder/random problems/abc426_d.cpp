#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T> void print_vec(vector<T>& a) {for (int i = 0; i < a.size(); i++) cout << a[i] << " ";cout << endl;}

void solve() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;

    s = " " + s;

    vector<int> ps(n + 1);
    for (int i = 1; i <= n; i++) ps[i] = ps[i-1] + (s[i] == '0');
    
    auto find_ans = [&](char c) {
        int best_ans = 1e9;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == c) cnt++;
            else cnt = 0;
            int cnt_0_left = ps[i-cnt], cnt_0_right = ps[n] - ps[i];
            int cnt_1_left = i - cnt - cnt_0_left, cnt_1_right = n - i - cnt_0_right;
            int cnt_0 = cnt_0_left + cnt_0_right;
            int cnt_1 = cnt_1_left + cnt_1_right;

            int cur_ans;
            if (c == '0') cur_ans = 2*cnt_0 + cnt_1;
            else cur_ans = cnt_0 + 2*cnt_1;
            best_ans = min(best_ans, cur_ans);
        }
        return best_ans;
    };

    int ans = min(find_ans('0'), find_ans('1'));
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