#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

bool is_prime(int n) {
    bool prime = n != 1;
    for (int i = 2; i * i <= n; i++) {
        prime &= (n % i) != 0;
    }
    return prime;
}

void solve() {
    int n, k;
    cin >> n >> k; 

    if (n == 1) {
        string s = "";
        for (int i = 0; i < k; i++) {
            s += '1';
        }

        n = stoi(s);
        if (is_prime(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    }

    if (is_prime(n) && k == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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