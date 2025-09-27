#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll get_ans(string& s, ll n, char c) {
    vector<ll> a;
    for (ll i = 0; i < n; i++) {
        if (s[i] == c) a.push_back(i);
    }
    if (a.size() == 0) return 1e9;

    ll idx = a[a.size() / 2];
    ll ans = 0;
    vector<ll> left, right;
    for (ll i = 0; i < n; i++) {
        if (i < idx && s[i] == c) left.push_back(i);
        if (i > idx && s[i] == c) right.push_back(i);
    }
    
    reverse(left.begin(), left.end());
    
    ll cnt_left = 0, cnt_right = 0;
    for (auto i : left) {
        ans += abs(idx - i - 1 - cnt_left);
        cnt_left++;
    }

    for (auto i : right) {
        ans += abs(i - idx - 1 - cnt_right);
        cnt_right++;
    }

    return ans;
}

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    ll ans1 = get_ans(s, n, 'a');
    ll ans2 = get_ans(s, n, 'b');
    cout << min(ans1, ans2) << endl;
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