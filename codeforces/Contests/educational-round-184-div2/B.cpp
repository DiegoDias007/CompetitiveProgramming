#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    string s;
    cin >> s;
    ll n = s.size();

    vector<ll> ps(n), ss(n);
    for (ll i = 1; i < n; i++) {
        ps[i] = ps[i - 1] + (s[i - 1] == '<');
    }

    for (ll i = n - 2; i >= 0; i--) {
        ss[i] = ss[i + 1] + (s[i + 1] == '>');
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        bool check_left = (s[i] == '<');
        bool check_right = (s[i] == '>');
        if (s[i] == '*') {
            check_left = true;
            check_right = true;
        }

        if (check_left) {
            if (ps[i] < i) {
                cout << -1 << endl;
                return;
            }
            ans = max(ans, i + 1);
        }

        if (check_right) {
            ll cnt_right = n - i - 1;
            if (ss[i] < cnt_right) {
                cout << -1 << endl;
                return;
            }
            ans = max(ans, cnt_right + 1);
        }
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