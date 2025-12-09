#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

/*

    dp[i][c][p]: quantidade de numeros com i
    digitos, sem digitos adjacentes iguais, que seguem
    o seguinte formato: cp___...___

    caso base:
        dp[1][0][-1] ... dp[1][9][-1] = 1.

*/

int cnt_digits(ll x) {
    int dig = 1;
    while (x >= 10) {
        x /= 10;
        dig++;
    }
    return dig;
}

int get_digit(ll x, int digit) {
    ll pw = 1;
    for (int i = 0; i < digit - 1; i++) pw *= 10;
    return (x / pw) % 10;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    int n = 18;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(10, vector<ll>(10)));
    for (int d = 0; d < 10; d++) dp[1][d][0] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int c = 0; c < 10; c++) {
            for (int p = 0; p < 10; p++) {
                if (c == p) continue;
                for (int k = 0; k < 10; k++) {
                    dp[i][c][p] += dp[i-1][p][k];
                }
            }
        }
    }

    auto g = [&](auto g, ll x, int digit, int pdigit, bool flag) -> ll {
        int cur_digit = get_digit(x, digit);
        if (digit == 1) return (cur_digit + 1) - (cur_digit >= pdigit);
        ll y = 0;
        for (int c = flag; c < cur_digit; c++) {
            if (c == pdigit) continue;
            for (int p = 0; p < 10; p++) {
                y += dp[digit][c][p];
            }
        }
        if (cur_digit != pdigit) y += g(g, x, digit - 1, cur_digit, false);
        return y;
    };

    // f(x): quantidade de numeros <= x sem
    // digitos adjacentes iguais
    auto f = [&](ll x) -> ll {
        if (x < 0) return 0;
        ll y = 0;
        int digits = cnt_digits(x);
        for (int i = 1; i < digits; i++) {
            for (int c = i > 1; c < 10; c++) {
                for (int p = 0; p < 10; p++) {
                    y += dp[i][c][p];
                }
            }
        }
        y += g(g, x, digits, 10, true);
        return y;
    };

    ll ans = f(b) - f(a - 1);
    cout << ans << endl;
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