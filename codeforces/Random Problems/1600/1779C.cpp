// https://codeforces.com/problemset/problem/1779/C

#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

ll calc_left(vector<ll>& a, ll m, ll m_sum) {
    ll ops = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll cur_sum = 0;
    for (int i = m + 1; i < a.size(); i++) {
        pq.push(a[i]);
        cur_sum += a[i];
        if (cur_sum < 0) {
            ops++;
            cur_sum -= 2*pq.top();
            pq.pop();
        }
    }
    return ops;
}

ll calc_right(vector<ll>& a, ll m, ll m_sum) {
    vector<ll> ps(m);
    for (int i = 0; i < m; i++) {
        ps[i] = (i > 0 ? ps[i - 1] : 0) + a[i];
    }

    priority_queue<ll> pq;
    pq.push(a[m]);
    ll ops = 0;
    ll cur_sum = 0;
    for (int i = m - 1; i >= 0; i--) {
        while (ps[i] < m_sum) {
            ops++;
            m_sum -= 2*pq.top();
            pq.pop();
        }
        pq.push(a[i]);
    }
    return ops;
}

void solve() {
    ll n, m;
    cin >> n >> m; 
    m--;
    vector<ll> a(n);
    ll m_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i <= m) m_sum += a[i];
    }

    ll ans = calc_left(a, m, m_sum) + calc_right(a, m, m_sum);
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