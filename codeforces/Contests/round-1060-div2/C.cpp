#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

const int N = 200500;
map<int, int> cnt;
vector<int> primes(N);

vector<int> fact(int n, bool flag = true) {
    vector<int> f;
    int prev = -1;
    while (primes[n] > 1) {
        if (primes[n] != prev) {
            if (flag) cnt[primes[n]]++;
            prev = primes[n];
        }
        f.push_back(primes[n]);
        n /= primes[n];
    }
    return f;
}

void solve() {
    int n;
    cin >> n;
    cnt.clear();
    vector<int> a(n), b(n);
    vector<vector<int>> facts_store(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        facts_store[i] = fact(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    bool ok = false;
    for (auto [d, c] : cnt) {
        ok |= c > 1;
    }

    if (ok) {
        cout << 0 << endl;
        return;
    }

    if (cnt[2] == 1) {
        cout << 1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        vector<int> f_bef = facts_store[i];
        vector<int> f = fact(a[i] + 1, false);

        for (auto factor : f_bef) cnt[factor]--;
        
        for (auto factor : f) {
            if (cnt[factor] == 1) {
                cout << 1 << endl;
                return;
            }
        }

        for (auto factor : f_bef) cnt[factor]++;
    }

    cout << 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    iota(primes.begin(), primes.end(), 0);
    for (int i = 2; i < N; i++) {
        if (primes[i] != i) continue;
        for (int j = i + i; j < N; j += i) {
            if (primes[j] == j) primes[j] = i;
        }
    }

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
