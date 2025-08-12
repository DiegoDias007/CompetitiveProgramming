// https://codeforces.com/problemset/problem/2008/E

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

vector<int> sub_vec(vector<int>& a, vector<int>& b) {
    vector<int> out(a.size());
    for (int i = 0; i < a.size(); i++) out[i] = a[i] - b[i];
    return out;
}

vector<int> add_vec(vector<int>& a, vector<int>& b) {
    vector<int> out(a.size());
    for (int i = 0; i < a.size(); i++) out[i] = a[i] + b[i];
    return out;
}

int calc_ans(vector<int> cnt_even, vector<int> cnt_odd, int n) {
    int mx_even = 0, mx_odd = 0;
    for (int i = 0; i < 26; i++) {
        mx_even = max(mx_even, cnt_even[i]);
        mx_odd = max(mx_odd, cnt_odd[i]);
    }
    int change_even = n / 2 - mx_even;
    int change_odd = n / 2 - mx_odd;
    return change_even + change_odd;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> ps_even(n + 1, vector<int>(26)), ps_odd(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
        ps_even[i] = ps_even[i - 1];
        ps_odd[i] = ps_odd[i - 1];
        if ((i - 1) % 2 == 0) ps_even[i][s[i - 1] - 'a']++;
        else ps_odd[i][s[i - 1] - 'a']++;
    }

    if (n % 2 == 0) {
        cout << calc_ans(sub_vec(ps_even[n], ps_even[0]), sub_vec(ps_odd[n], ps_even[0]), n) << endl;
        return;
    }

    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        vector<int> left_even = sub_vec(ps_even[i], ps_even[0]), left_odd = sub_vec(ps_odd[i], ps_odd[0]);
        vector<int> right_even = sub_vec(ps_odd[n], ps_odd[i + 1]), right_odd = sub_vec(ps_even[n], ps_even[i + 1]);
        int cur_ans = calc_ans(add_vec(left_even, right_even), add_vec(left_odd, right_odd), n - 1) + 1;
        ans = min(ans, cur_ans);
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