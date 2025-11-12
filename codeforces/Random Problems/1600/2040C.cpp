#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, k;
    cin >> n >> k;

    if (n <= 63 && (1ll << (n - 1)) < k) {
        cout << -1 << endl;
        return;
    }

    ll rem = n;

    vector<ll> ans(n);
    ll l = 0, r = n - 1;
    
    while (rem > 63) {
        ans[l] = l + 1;
        l++;
        rem--;
    }
    
    ll current = l + 1;
    ll cur_k = 1;
    while (rem > 1) {
        ll add = 1ll << (rem - 2);
        ll new_k = cur_k + add;
        if (new_k <= k) {
            cur_k += add;
            ans[r] = current;
            r--;
        } else {
            ans[l] = current;
            l++;
        }

        current++;
        rem--;
    }

    ans[l] = current;

    print_vec(ans);
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