#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll ask(ll type, ll x1, ll x2) {
    ll tmp;
    cout << type << " " << x1 << " " << x2  << endl;
    cin >> tmp;
    return tmp;
}

void solve() {
    ll n;
    cin >> n;

    ll original = ask(1, 1, n);
    ll change = ask(2, 1, n);
    ll size = change - original;

    ll true_r;
    ll l = 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll o = ask(1, mid, n);
        ll c = ask(2, mid, n);
        if (o == c) {
            r = mid - 1;
        } else {
            true_r = mid;
            l = mid + 1;
        }
    }

    ll true_l = true_r - size + 1;
    cout << "! " << true_l << " " << true_r << endl;
}

int main() {

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}