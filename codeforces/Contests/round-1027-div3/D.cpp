#include <bits/stdc++.h>
 
#define endl "\n"
typedef long long ll;
using namespace std;
 
template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}
 
void solve() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vector<ll> pxmin(n, 1e9), pxmax(n), pymin(n, 1e9), pymax(n);
    for(ll i = 1; i < n; i++){
        pxmin[i] = min(pxmin[i-1], x[i - 1]);
        pxmax[i] = max(pxmax[i-1], x[i - 1]);
        pymin[i] = min(pymin[i-1], y[i - 1]);
        pymax[i] = max(pymax[i-1], y[i - 1]);
    }
 
    vector<ll> sxmin(n, 1e9), sxmax(n), symin(n, 1e9), symax(n);
    for(ll i = n - 2; i >= 0; i--){
        sxmin[i] = min(sxmin[i + 1], x[i + 1]);
        sxmax[i] = max(sxmax[i+1], x[i + 1]);
        symin[i] = min(symin[i+1], y[i + 1]);
        symax[i] = max(symax[i+1], y[i + 1]);
    }
 
    ll ans = 2e18;
    for (ll i = 0; i < n; i++) {
        ll mn_x = min(pxmin[i], sxmin[i]);
        ll mx_x = max(pxmax[i], sxmax[i]);
        ll mn_y = min(pymin[i], symin[i]);
        ll mx_y = max(pymax[i], symax[i]);
 
        ll size_x = (mx_x - mn_x + 1);
        ll size_y = (mx_y - mn_y + 1);
        ll cells = size_x * size_y;
        if (cells == n - 1) {
            cells += min(size_x,size_y);
        }
        ans = min(ans, cells);
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