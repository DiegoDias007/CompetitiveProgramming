#include <bits/stdc++.h>

#define endl '\n'
typedef long long ll;
using namespace std;

template <typename T>T gcd(T a, T b) {if (b == 0) return a; return gcd(b, a % b);}
template <typename T> T lcm(T a, T b) {return (a * b) / gcd(a, b);}
template <typename K> void print_vec(const vector<K>& vec) {for(size_t i = 0; i < vec.size(); ++i) {cout << vec[i];if(i != vec.size() - 1) {cout << " ";}}cout << endl;}

int C2(int n) {
    return (n * (n - 1)) / 2;
}

const int N = 30;
const int S = C2(N);
vector<vector<int>> dp(N + 1, vector<int>(S + 1));

void solve() {
    int n, k;
    cin >> n >> k;

    int good = C2(n) - k;
    if (dp[n][good] == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> lenghts;
    int i = n;
    while (i > 0) {
        int l = dp[i][good];
        lenghts.push_back(l);
        i -= l;
        good -= C2(l); 
    }

    assert(i == 0);
    int ans = C2(n);
    for (auto l : lenghts) ans -= C2(l);
    assert(ans == k);
    
    reverse(lenghts.begin(), lenghts.end());

    vector<int> a(n + 1);
    int top = n;
    i = 1;
    while (!lenghts.empty()) {
        int cur_l = lenghts.back();
        lenghts.pop_back();

        int start = top - cur_l + 1;
        top = start - 1;
        for (int idx = i; idx < i + cur_l; idx++) {
            a[idx] = start;
            start++;
        }
        i += cur_l;
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    dp[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int s = 0; s <= S; s++) {
            for (int l = 1; l <= i; l++) {
                if (s - C2(l) >= 0 && dp[i - l][s - C2(l)] != 0) {
                    dp[i][s] = l;
                    break;
                }
            }
        }
    }
    
    int t;
    cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}