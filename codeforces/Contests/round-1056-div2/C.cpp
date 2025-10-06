#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int n;
vector<int> a;

bool check(int side) {
    vector<int> b(n);
    b[0] = side;
    for (int i = 1; i < n; i++) {
        int dif = a[i] - a[i - 1];
        if (dif == 0) {
            b[i] = (b[i - 1] == 0 ? 1 : 0);
        } else if (dif == 1) {
            b[i] = 0;
        } else {
            b[i] = 1;
        }
    }

    vector<int> sum_right(n);
    for (int i = n - 2; i >= 0; i--) {
        sum_right[i] = sum_right[i + 1] + (b[i + 1] == 1);
    }

    int sum_left = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        ok &= (sum_left + sum_right[i] + 1) == a[i];
        sum_left += b[i] == 0;
    }
    return ok;
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool ok = true;
    for (int i = 1; i < n; i++) ok &= abs(a[i] - a[i - 1]) <= 1;

    if (!ok) {
        cout << 0 << endl;
        return;
    }

    int ans = 0;
    ans += check(0);
    ans += check(1);
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