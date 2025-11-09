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
    map<int, int> mp;
    mp[0] = 1e9;
    ll di = 1e9;
    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;

        mp[xi] = 1e9;
        auto ptr = mp.find(xi);
        
        if (ptr != mp.begin()) {
            int prv = (*prev(ptr)).first;
            int dist = xi - prv;
            mp[xi] = min(mp[xi], dist);
            if (mp[xi] < mp[prv]) {
                di -= mp[prv] - dist;
                mp[prv] = dist;
            }
        }

        if (next(ptr) != mp.end()) {
            int nxt = (*next(ptr)).first;
            int dist = nxt - xi;
            mp[xi] = min(mp[xi], dist);
            if (dist < mp[nxt]) {
                di -= mp[nxt] - dist;
                mp[nxt] = dist;
            }
        }

        di += mp[xi];
        cout << di << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}