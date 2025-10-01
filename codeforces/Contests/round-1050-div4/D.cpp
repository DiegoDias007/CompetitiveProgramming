#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> a;
    for (ll i = 0; i < n; i++) {
        ll cur;
        cin >> cur;
        if (cur % 2 == 0) ans += cur;
        else a.push_back(cur);
    }

    if (a.size() == 0) {
        cout << 0 << endl;
        return;
    }


    sort(a.begin(), a.end());
    ll l = 0, r = a.size() - 1;
    bool eat = true;
    while (l <= r) {
        if (eat) {
            ans += a[r];
            r--;
        } else {
            l++;
        }
        eat = !eat;
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