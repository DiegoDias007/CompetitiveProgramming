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
    string s;
    cin >> s;

    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; i++) {
        cnt_a += s[i] == 'a';
        cnt_b += s[i] == 'b';
    }

    int dif = cnt_a - cnt_b;
    if (dif == 0) {
        cout << 0 << endl;
        return;
    }

    if (abs(dif) == n) {
        cout << -1 << endl;
        return;
    }

    int ans = n;
    map<int, int> mp;
    mp[0] = -1;
    int cur_dif = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') cur_dif++;
        else cur_dif--;
        int need = cur_dif - dif;
        if (mp.find(need) != mp.end()) {
            ans = min(ans, i - mp[need]);
        }
        mp[cur_dif] = i;
    }
    if (ans == n) cout << -1 << endl;
    else cout << ans << endl;
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