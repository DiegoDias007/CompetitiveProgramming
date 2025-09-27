#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

void solve() {
    ll n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    map<ll, ll> cnt_good, cnt_right;
    ll right = 0;
    ll good_ptr = 0;
    for (ll left = 0; left < n; left++) {
        while (good_ptr < n && cnt_good.size() < k) {
            cnt_good[a[good_ptr]]++;
            good_ptr++;
        }
        
        while (right < n && cnt_right.size() <= k) {
            cnt_right[a[right]]++;
            right++;
        }

        if (cnt_right.size() > k) {
            right--;
            cnt_right.erase(a[right]);
        }

        if (cnt_good.size() == k && cnt_right.size() == k) {
            ll mx_size = right - left;
            ll mn_size = good_ptr - left;
            ll my_l = max(l, mn_size), my_r = min(mx_size, r);
            // cout << "-----------------" << endl;
            // cout << left << " " << right << " " << good_ptr << endl;
            // cout << my_l << " " << my_r << endl;
            // cout << "-----------------" << endl;
            if (my_r >= my_l) ans += my_r - my_l + 1;
        }

        cnt_good[a[left]]--;
        if (cnt_good[a[left]] == 0) cnt_good.erase(a[left]);

        cnt_right[a[left]]--;
        if (cnt_right[a[left]] == 0) cnt_right.erase(a[left]);
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