#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

vector<ll> s10(18);
ll AAA = 0;

ll pw(ll a, ll b ) {
    if (b == 0) return 1;
    ll p = pw(a, b / 2);
    if (b % 2 == 0) return p * p;
    else return p * p * a;
}

ll pos(ll k) {
    ll n_digits = 0;
    ll digits = 1;
    ll numbers = 9;
    while (n_digits + numbers * digits < k) {
        n_digits += numbers * digits;
        digits++;
        numbers *= 10;
    }

    ll add = (k - n_digits - 1) / digits;
    ll base = 1;
    for (ll i = 1; i < digits; i++) base *= 10;
    ll want = base + add;
    string want_s = to_string(want);
    n_digits += add * digits;
    for (int i = 0; i < digits; i++) {
        if (n_digits == k) break;
        n_digits++;
        AAA += want_s[i] - '0';
    }
    return want;
}

ll f(ll x) {
    if (x <= 9) return x * (x + 1) / 2;

    ll digits = 0;
    ll y = x;
    while (y) {
        y /= 10;
        digits++;
    }

    ll last_d = x / pw(10, digits - 1);
    ll sum = pw(10, digits - 1) * (last_d - 1) * (1 + last_d - 1) / 2 + last_d * s10[digits-1];
    ll r = x % pw(10, digits - 1);
    return sum + last_d * (r + 1) + f(r);
}

void solve() {
    ll k;
    cin >> k;
    AAA = 0;
    ll x = pos(k);
    ll ans = f(x - 1) + AAA;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // s10[i]: soma dos digitos de 1 ate 10^i - 1
    s10[1] = 45;
    for (ll i = 2; i < 18; i++) {
        s10[i] = 45 * (pw(10, i - 1)) + s10[i - 1] * 10;
    }
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}