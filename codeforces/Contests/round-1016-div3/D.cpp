#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool in_between(pair<ll, ll> p1, pair<ll, ll> p2, pair<ll, ll> p) {
    return p1.first <= p.first && p.first <= p2.first && p1.second <= p.second && p.second <= p2.second;
}

ll get_number(pair<ll, ll> p1, pair<ll, ll> p2, ll now, pair<ll, ll> p, ll n) {
    if (p1 == p2) return now;

    ll now1 = now, now2 = now + n, now3 = now + 2*n, now4 = now + 3*n;
    ll half_x = (p1.first + p2.first) / 2 + 1, half_y = (p1.second + p2.second) / 2 + 1;
    bool first = in_between(p1, {half_x - 1, half_y - 1}, p);
    bool second = in_between({half_x, half_y}, p2, p);
    bool third = in_between({half_x, p1.second}, {p2.first, half_y - 1}, p);

    if (first) {
        return get_number(p1, {half_x - 1, half_y - 1}, now1, p, n / 4);
    } else if (second) {
        return get_number({half_x, half_y}, p2, now2, p, n / 4);
    } else if (third) {
        return get_number({half_x, p1.second}, {p2.first, half_y - 1}, now3, p, n / 4);
    } else {
        return get_number({p1.first, half_y}, {half_x - 1, p2.second}, now4, p, n / 4);
    }
}

pair<ll, ll> get_xy(pair<ll, ll> p1, pair<ll, ll> p2, ll now, ll number, ll n) {
    if (p1 == p2) return p1;

    ll now1 = now, now2 = now + n, now3 = now + 2*n, now4 = now + 3*n;
    ll half_x = (p1.first + p2.first) / 2 + 1, half_y = (p1.second + p2.second) / 2 + 1;
    bool first = now1 <= number && number < now2;
    bool second = now2 <= number && number < now3;
    bool third = now3 <= number && number < now4;

    if (first) {
        return get_xy(p1, {half_x - 1, half_y - 1}, now1, number, n / 4);
    } else if (second) {
        return get_xy({half_x, half_y}, p2, now2, number, n / 4);
    } else if (third) {
        return get_xy({half_x, p1.second}, {p2.first, half_y - 1}, now3, number, n / 4);
    } else {
        return get_xy({p1.first, half_y}, {half_x - 1, p2.second}, now4, number, n / 4);
    }
}

void solve() {
    ll n, q;
    cin >> n >> q;
    ll x1 = 1LL << n, x2 = 1LL << (2*(n-1));
    pair<ll, ll> p1 = {1, 1}, p2 = {x1, x1};
    while (q--) {
        string type;
        cin >> type;
        if (type == "->") {
            ll a, b;
            cin >> a >> b;
            cout << get_number(p1, p2, 1, {a, b}, x2) << endl;
        } else {
            ll a;
            cin >> a;
            pair<ll, ll> point = get_xy(p1, p2, 1, a, x2);
            cout << point.first << " " << point.second << endl;
        }
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